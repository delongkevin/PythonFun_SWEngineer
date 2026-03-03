# Copyright (c) 2020, Texas Instruments Incorporated
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# *  Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# *  Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# *  Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

use strict;
use POSIX;
use Win32::OLE;
use Cwd 'abs_path';
use File::Basename qw();

my $BIT_MAX;

sub ddrss_eye_plot
{
    my $excel = shift;
    my $book = shift;
    my $max_val = shift;
    my $dq_bit = shift;
    my $mc = shift;
    my $mr = shift;

    #warn "max_val is $max_val\n";
    warn "\tFormatting the margin analysis output for dq_bit $dq_bit\n";
    
    my @color = (15773440,14791695,13809951,12828207,11846463,10864719,9882975,8901231,7919487,6937743,5955999,4974255,3992511,3010767,2029023,1047279,65535,61439,57343,53247,49151,45055,40959,36863,32767,28671,24575,20479,16383,12287,8191,4095,255);
    
    my $sheet;
    
    $sheet = $book->Worksheets->Add;
    $sheet->{Name} = "DQ$dq_bit";
    
    # Fix Me --> Need to calculate actual data set
    $book->PivotCaches->Create({SourceType=>1,SourceData=>"J7_DDRSS_Tool_CSV_Data!R1C1:R153921C12"})->CreatePivotTable({TableDestination=>"DQ$dq_bit!R17C5",TableName=>"PT_DQ$dq_bit"});
    #$book->PivotCaches->Create({SourceType=>1,SourceData=>"J7_DDRSS_Tool_CSV_Data!R1C1:R602689C12"})->CreatePivotTable({TableDestination=>"DQ$dq_bit!R17C5",TableName=>"PT_DQ$dq_bit"});
    
    $sheet->PivotTables("PT_DQ$dq_bit")->AddDataField({Field=>$sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("plot_f2_cs0_train"), Caption=>"Sum of plot_f2_cs0_train", Function=>-4157});

    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("dqs_edge")->{Orientation} = 1;
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("dqs_edge")->{Position} = 1;
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("vref_dec")->{Orientation} = 1;
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("vref_dec")->{Position} = 2;
    
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("read_delay_dec")->{Orientation} = 2;
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("read_delay_dec")->{Position} = 1;
    
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("bit")->{Orientation} = 3;
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("bit")->{Position} = 1;
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("bit")->ClearAllFilters();
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("bit")->{CurrentPage} = $dq_bit;
    
    $sheet->PivotTables("PT_DQ$dq_bit")->PivotFields("vref_dec")->AutoSort({Order=>2,Field=>"vref_dec"});
    
    # Red = 255
    # Yellow = 65,535
    # Blue = 16,711,680
    my $col;
    my $row;
    my $data;
    my $index;
    
    # Rising Edge
    for ($col = 6; $col < (6+$mc); $col++)
    {
        for ($row = 20; $row < (20+$mr); $row++){
            $data = $sheet->Cells($row, $col)->{Value};
        
            if($data < 0){
                $sheet->Cells($row, $col)->Interior->{Color}=10498160;
            }elsif($data == 0){
                $sheet->Cells($row, $col)->Interior->{Color}=5287936;
            }else{
                for($index = 0; $index < 33; $index++)
                {
                    if((($data / $max_val) > ($index/33)) and (($data / $max_val) <= (($index+1)/33))){
                        $sheet->Cells($row, $col)->Interior->{Color}=$color[$index];
                    }
                }
            }
        }
    }
    
    # Falling Edge
    for ($col = 6; $col < (6+$mc); $col++)
    {
        for ($row = (20+$mr+1); $row < (20+$mr+1+$mr); $row++){
            $data = $sheet->Cells($row, $col)->{Value};
        
            if($data < 0){
                $sheet->Cells($row, $col)->Interior->{Color}=10498160;
            }elsif($data == 0){
                $sheet->Cells($row, $col)->Interior->{Color}=5287936;
            }else{
                for($index = 0; $index < 33; $index++)
                {
                    if((($data / $max_val) > ($index/33)) and (($data / $max_val) <= (($index+1)/33))){
                        $sheet->Cells($row, $col)->Interior->{Color}=$color[$index];
                    }
                }
            }
        }
    }
    
    $excel->ActiveWindow->{Zoom}=60;
    
    $sheet->Cells->Select();
    my $range = $excel->Selection();
    $range->{ColumnWidth} = 300/$mc;
    
    # Tool Name
    #$sheet->Range("G1:BR2")->Select();
    $sheet->Range($sheet->Cells(1,6),$sheet->Cells(2,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->Font->{Color}=0;
    $range->Font->{Size}=16;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="Jacinto7 DDRSS TOOL";
    
    # Revision
    $sheet->Range($sheet->Cells(3,6),$sheet->Cells(3,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->Font->{Color}=0;
    $range->Font->{Size}=12;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="Revision: Beta Release - September 2020";
    
    # Copyright
    $sheet->Range($sheet->Cells(4,6),$sheet->Cells(4,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->Font->{Color}=0;
    $range->Font->{Size}=12;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="Copyright (c) 2020, Texas Instruments Incorporated";
    
    # Notice
    $sheet->Range($sheet->Cells(6,6),$sheet->Cells(7,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->Font->{Color}=-16776961;
    $range->Font->{Size}=16;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="IMPORTANT NOTICE AND DISCLAIMER";
    
    # Notice-1
    $sheet->Range($sheet->Cells(8,6),$sheet->Cells(9,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->{WrapText}="True";
    $range->Font->{Color}=0;
    $range->Font->{Size}=10;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="TI PROVIDES TECHNICAL AND RELIABILITY DATA (INCLUDING DATASHEETS), DESIGN RESOURCES (INCLUDING REFERENCE DESIGNS), APPLICATION OR OTHER DESIGN ADVICE, WEB TOOLS, SAFETY INFORMATION, AND OTHER RESOURCES “AS IS” AND WITH ALL FAULTS, AND DISCLAIMS ALL WARRANTIES, EXPRESS AND IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY RIGHTS.";

    # Notice-2
    $sheet->Range($sheet->Cells(10,6),$sheet->Cells(12,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->{WrapText}="True";
    $range->Font->{Color}=0;
    $range->Font->{Size}=10;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="These resources are intended for skilled developers designing with TI products. You are solely responsible for (1) selecting the appropriate TI products for your application, (2) designing, validating and testing your application, and (3) ensuring your application meets applicable standards, and any other safety, security, or other requirements. These resources are subject to change without notice. TI grants you permission to use these resources only for development of an application that uses the TI products described in the resource. Other reproduction and display of these resources is prohibited. No license is granted to any other TI intellectual property right or to any third party intellectual property right. TI disclaims responsibility for, and you will fully indemnify TI and its representatives against, any claims, damages, costs, losses, and liabilities arising out of your use of these resources.";
    
    # Notice-3
    $sheet->Range($sheet->Cells(13,6),$sheet->Cells(14,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->{WrapText}="True";
    $range->Font->{Color}=0;
    $range->Font->{Size}=10;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="TI products are provided subject to TI Terms of Sale (www.ti.com/legal/termsofsale.html) or other applicable terms available either on ti.com or provided in conjunction with such TI products. TI provision of these resources does not expand or otherwise alter TI applicable warranties or warranty disclaimers for TI products.";

    # Add border
    $sheet->Range($sheet->Cells(1,6),$sheet->Cells(14,6+$mc))->Select();
    $range = $excel->Selection();
    $range->Borders(5)->{LineStyle}=-4142;
    $range->Borders(6)->{LineStyle}=-4142;
    $range->Borders(7)->{LineStyle}=1;
    $range->Borders(7)->{ThemeColor}=1;
    
    $range->Borders(8)->{LineStyle}=1;
    $range->Borders(8)->{ThemeColor}=1;
    $range->Borders(9)->{LineStyle}=1;
    $range->Borders(9)->{ThemeColor}=1;
    $range->Borders(10)->{LineStyle}=1;
    $range->Borders(10)->{ThemeColor}=1;
    $range->Borders(11)->{LineStyle}=1;
    $range->Borders(11)->{ThemeColor}=1;
    $range->Borders(12)->{LineStyle}=1;
    $range->Borders(12)->{ThemeColor}=1;
    
    # Rising Edge
    $sheet->Range("A20:D56")->Select();
    $sheet->Range($sheet->Cells(20,1),$sheet->Cells(20+$mr,4))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->{WrapText}="True";
    $range->Font->{Color}=0;
    $range->Font->{Size}=24;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="DQ$dq_bit Margin for DQS Rising Edge";
    
    # Falling Edge
    $sheet->Range($sheet->Cells(20+$mr+1,1),$sheet->Cells(20+$mr+1+$mr,4))->Select();
    $range = $excel->Selection();
    $range->Merge();
    $range->{HorizontalAlignment}=-4108;
    $range->{VerticalAlignment}=-4108;
    $range->{WrapText}="True";
    $range->Font->{Color}=0;
    $range->Font->{Size}=24;
    $range->Font->{Bold}="True";
    $excel->ActiveCell->{FormulaR1C1}="DQ$dq_bit Margin for DQS Falling Edge";
    
    $sheet->Range("A1")->Select();
}

foreach my $file (@ARGV)
{
	open(IN, "<$file") || die "Error: Can't open input file, $file\n";
    
	my $xls = $file;
	$xls =~ s/\.[^.]+$//;
	$xls =~ s/serial/parallel/;
	$xls .= ".xlsx";
    my $out = "J7_DDRSS_Tool_CSV_Data.csv";
    
    warn "\tProcessing input file $file and converting to csv format\n";
    
    my @mr14;
    
    my @write_delay_f0_cs0;
    my @write_delay_f0_cs1;
    my @write_delay_f1_cs0;
    my @write_delay_f1_cs1;
    my @write_delay_f2_cs0;
    my @write_delay_f2_cs1;
    
    my $plot_f1_cs0_train;
    my $plot_f1_cs1_train;
    my $plot_f2_cs0_train;
    my $plot_f2_cs1_train;
    
    my @read_delay_f1_cs0_fall;
    my @read_delay_f1_cs1_fall;
    my @read_delay_f2_cs0_fall;
    my @read_delay_f2_cs1_fall;
    my @read_delay_f1_cs0_rise;
    my @read_delay_f1_cs1_rise;
    my @read_delay_f2_cs0_rise;
    my @read_delay_f2_cs1_rise;

	open(OUT, ">$out") || die "Error: Can't open temporary csv file, $out\n";

	# print OUT "eye_type,vref_hex,vref_dec,read_delay_hex,read_delay_dec,bit,dqs_edge,fail_count,vref_train,rddly_train,vref_offset,rddly_offset\n";
    print OUT "eye_type,vref_hex,vref_dec,read_delay_hex,read_delay_dec,bit,dqs_edge,fail_count,plot_f1_cs0_train,plot_f1_cs1_train,plot_f2_cs0_train,plot_f2_cs1_train\n";

    my ($eye_type, $vref_step, $dly_step);
	my ($vdd,$ddr_configname,$pattern_name,$ddr_rate,$vref_hex,$vref_dec,$rddly_hex,$rddly_dec,$bit,$dqs_edge,$fail_count,$d_f0_cs0,$d_f0_cs1,$d_f1_cs0,$d_f1_cs1,$d_f2_cs0,$d_f2_cs1,$wr_vref_train);
	my %vref_train;
	my %rddly_train;
	my ($vref_offset,$rddly_offset);
    my $max_fail = 0;

	$bit = 128; # needs to be larger than or equal to absolute max
    $dly_step = 0;
    $vref_step = 0;

	while (my $line = <IN>)
	{
        $eye_type =           $1 if ($line =~ /eye_type=(.*)/);
		$vref_step =          $1 if ($line =~ /VREF Step Size \(enter decimal value; min value is 2\): (.*)/);
        $dly_step =           $1 if ($line =~ /Delay Step Size \(enter decimal value; min value is 8\): (.*)/);
        $vdd =                $1 if ($line =~ /vdd=(.*)/);
		$ddr_configname =     $1 if ($line =~ /ddr_configname=(.*)/);
		$pattern_name =       $1 if ($line =~ /pattern_name=(.*)/);
		$ddr_rate =           $1 if ($line =~ /ddr_rate=(.*)/);
		$vref_train{$1} =     $2 if ($line =~ /vref_train_b([0-9])=(.*)/);
        $BIT_MAX =            $1 if ($line =~ /Bus Width: (.*)/);
		
        if ($line =~ /rddly_train_b[0-9]_d([0-9]+)_([^=]+)=(.*)/)
		{
			my $bit_local = $1;
			my $dqs_edge_local = $2;
			my $trainval_local = $3;
			$dqs_edge_local = 0 if ($dqs_edge_local eq "rise") ;
			$dqs_edge_local = 1 if ($dqs_edge_local eq "fall") ;

			$rddly_train{$bit_local,$dqs_edge_local} = $trainval_local;
		}
        
        # WRITE VREF
        if ($line =~ /mr14_f([0-9])_cs([0-9]): (.*)/)
        {
            push(@mr14, hex($3));
        }
        
        # READ VREF
        if ($line =~ /phy_vref_f([0-9])_bl([0-9]): (.*)/)
        {
            push(@mr14, hex($3));
        }
        
        # WRITE TRAINED VALUES
        if ($line =~ /write_delay, f0_cs0_dq([0-9]+) : (.*)/)
        {
            push(@write_delay_f0_cs0, hex($2));
            #warn "dq$1 is $2\n"
        }
        if ($line =~ /write_delay, f0_cs1_dq([0-9]+) : (.*)/)
        {
            push(@write_delay_f0_cs1, hex($2));
            #warn "dq$1 is $2\n"
        }
        if ($line =~ /write_delay, f1_cs0_dq([0-9]+) : (.*)/)
        {
            push(@write_delay_f1_cs0, hex($2));
            #warn "dq$1 is $2\n"
        }
        if ($line =~ /write_delay, f1_cs1_dq([0-9]+) : (.*)/)
        {
            push(@write_delay_f1_cs1, hex($2));
            #warn "dq$1 is $2\n"
        }
        if ($line =~ /write_delay, f2_cs0_dq([0-9]+) : (.*)/)
        {
            push(@write_delay_f2_cs0, hex($2));
            #warn "dq$1 is $2\n"
        }
        if ($line =~ /write_delay, f2_cs1_dq([0-9]+) : (.*)/)
        {
            push(@write_delay_f2_cs1, hex($2));
            #warn "dq$1 is $2\n"
        }
        
        # READ TRAINED VALUES
        if ($line =~ /read_delay_fall, f1_cs0_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f1_cs0_fall, hex($2));
        }
        if ($line =~ /read_delay_fall, f1_cs1_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f1_cs1_fall, hex($2));
        }
        if ($line =~ /read_delay_fall, f2_cs0_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f2_cs0_fall, hex($2));
        }
        if ($line =~ /read_delay_fall, f2_cs1_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f2_cs1_fall, hex($2));
        }
        if ($line =~ /read_delay_rise, f1_cs0_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f1_cs0_rise, hex($2));
        }
        if ($line =~ /read_delay_rise, f1_cs1_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f1_cs1_rise, hex($2));
        }
        if ($line =~ /read_delay_rise, f2_cs0_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f2_cs0_rise, hex($2));
        }
        if ($line =~ /read_delay_rise, f2_cs1_dq([0-9]+) : (.*)/)
        {
            push(@read_delay_f2_cs1_rise, hex($2));
        }
	
		if ($line =~ /vref=(.*)/)
		{
			$vref_dec =       $1;
			$vref_hex =       sprintf("0x%02x", $vref_dec);
		}
	
		if ($line =~ /rddly=(.*)/)
		{
			$rddly_dec = $1 ;
			$rddly_hex = sprintf("0x%02x", $rddly_dec);
		}
        
        if ($line =~ /wrdly=(.*)/)
		{
			$rddly_dec = $1 ;
			$rddly_hex = sprintf("0x%02x", $rddly_dec);
		}
	
		$dqs_edge =       $1 if ($line =~ /dqs_edge=(.*)/);
		
        
        if ($line =~ /^([0-9]+)$/)
		{
			$fail_count = $1;
			
            if($fail_count > $max_fail){
                $max_fail = $fail_count;
            }
            
            $bit ++;
			$bit = 0 if ($bit >= $BIT_MAX);
			my $byte_lane = int($bit/8);
            
            #$wd_f0_cs0 = $write_delay_f0_cs0[$bit];
            #$wd_f0_cs1 = $write_delay_f0_cs1[$bit];
            
            if($eye_type eq "write"){
                $d_f1_cs0 = $write_delay_f1_cs0[$bit];
                $d_f1_cs1 = $write_delay_f1_cs1[$bit];
                $d_f2_cs0 = $write_delay_f2_cs0[$bit];
                $d_f2_cs1 = $write_delay_f2_cs1[$bit];
            }
            
            if(($eye_type eq "read") and ($dqs_edge == 0)){
                $d_f1_cs0 = $read_delay_f1_cs0_rise[$bit];
                $d_f1_cs1 = $read_delay_f1_cs1_rise[$bit];
                $d_f2_cs0 = $read_delay_f2_cs0_rise[$bit];
                $d_f2_cs1 = $read_delay_f2_cs1_rise[$bit];
            }
            
            if(($eye_type eq "read") and ($dqs_edge == 1)){
                $d_f1_cs0 = $read_delay_f1_cs0_fall[$bit];
                $d_f1_cs1 = $read_delay_f1_cs1_fall[$bit];
                $d_f2_cs0 = $read_delay_f2_cs0_fall[$bit];
                $d_f2_cs1 = $read_delay_f2_cs1_fall[$bit];
            }
            
            # F1, CS0
            if($eye_type eq "write"){
                $wr_vref_train = ($bit < 16) ? $mr14[4] : $mr14[6];
            }
            if($eye_type eq "read"){
                $wr_vref_train = $mr14[($bit/8)];
            }
            
            if((abs($d_f1_cs0 - $rddly_dec) < $dly_step) and (abs($wr_vref_train - $vref_dec) < $vref_step))
            {
                $plot_f1_cs0_train = -1;
            }else{
                $plot_f1_cs0_train = $fail_count;
            }
            
            # F1, CS1
            if($eye_type eq "write"){
                $wr_vref_train = ($bit < 16) ? $mr14[5] : $mr14[7];
            }
            if($eye_type eq "read"){
                $wr_vref_train = $mr14[($bit/8)];
            }
            
            if((abs($d_f1_cs1 - $rddly_dec) < $dly_step) and (abs($wr_vref_train - $vref_dec) < $vref_step))
            {
                $plot_f1_cs1_train = -1;
            }else{
                $plot_f1_cs1_train = $fail_count;
            }
            
            # F2, CS0
            if($eye_type eq "write"){
                $wr_vref_train = ($bit < 16) ? $mr14[8] : $mr14[10];
            }
            if($eye_type eq "read"){
                $wr_vref_train = $mr14[($bit/8)+($BIT_MAX/8)];
            }
            
            if((abs($d_f2_cs0 - $rddly_dec) < $dly_step) and (abs($wr_vref_train - $vref_dec) < $vref_step))
            {
                $plot_f2_cs0_train = -1;
            }else{
                $plot_f2_cs0_train = $fail_count;
            }
            
            # F2, CS1
            if($eye_type eq "write"){
                $wr_vref_train = ($bit < 16) ? $mr14[9] : $mr14[11];
            }
            if($eye_type eq "read"){
                $wr_vref_train = $mr14[($bit/8)+($BIT_MAX/8)];
            }
            
            if((abs($d_f2_cs1 - $rddly_dec) < $dly_step) and (abs($wr_vref_train - $vref_dec) < $vref_step))
            {
                $plot_f2_cs1_train = -1;
            }else{
                $plot_f2_cs1_train = $fail_count;
            }
	
			#$vref_offset  = $vref_dec  - $vref_train{$byte_lane};
			#$rddly_offset = $rddly_dec - $rddly_train{$bit,$dqs_edge};
	
			# print OUT "$eye_type,$vref_hex,$vref_dec,$rddly_hex,$rddly_dec,$bit,$dqs_edge,$fail_count,$vref_train{$byte_lane},$rddly_train{$bit,$dqs_edge},$vref_offset,$rddly_offset\n";
            print OUT "$eye_type,$vref_hex,$vref_dec,$rddly_hex,$rddly_dec,$bit,$dqs_edge,$fail_count,$plot_f1_cs0_train,$plot_f1_cs1_train,$plot_f2_cs0_train,$plot_f2_cs1_train\n";
		}
	}
    
    close(OUT);
    
    my $fullpath = abs_path(__FILE__);
    my ($ksname, $kspath, $kssuffix) = File::Basename::fileparse($fullpath);
    #my ($ksname, $kspath, $kssuffix) = File::Basename::fileparse($0);
    #print "$kspath\n";
    
    my $WrkBkPath = $kspath."J7_DDRSS_Tool_CSV_Data.csv";
    my $excel = Win32::OLE->new('Excel.Application', sub {$_[0]->Quit;}) or die "Oops, cannot start Excel";
    my $book = $excel->Workbooks->Open($WrkBkPath) or die "Could not open temporary csv file";
    my $max_col;
    my $max_row;
    
    if($eye_type eq "write"){
        $max_col = floor(512 / $dly_step) + 1;
        $max_row = floor(72 / $vref_step) + 1;
    }
    
    if($eye_type eq "read"){
        $max_col = floor(320 / $dly_step) + 1;
        $max_row = floor(112 / $vref_step) + 1;
    }
    
    for($bit = ($BIT_MAX - 1); $bit >=0; $bit--){
        ddrss_eye_plot($excel,$book,$max_fail,$bit,$max_col,$max_row);
    }
    
    my $kspath2 = $kspath.$xls;
    $kspath2 =~ s/\//\\/g;
    print "\tSaving results to $kspath2\n";
    # $book->SaveAs({FileName=>($kspath2),FileFormat=>51});
    $book->SaveAs($kspath2,{FileFormat=>51});
    $book->Close(0);
    
    print "\tCleaning temporary files...\n";
    unlink $WrkBkPath;
    undef $excel;
    
    print "\tDONE!\n";
}
