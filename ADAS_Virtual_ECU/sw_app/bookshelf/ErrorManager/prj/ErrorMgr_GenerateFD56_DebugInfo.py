

FD56_PackedOrder_orderedList= ['B','QM']
def GenerateFD56_DebugInfo(enums,RootFolder):
    byte=0
    bit=0
    data_list=dict([(asil,[]) for asil in FD56_PackedOrder_orderedList])
    for asil in FD56_PackedOrder_orderedList:
        #Align to 4 byte boundary and start
        if(bit> 0):
            byte=byte+1
            bit=0
        if(byte%4 != 0):
            byte=byte+(4-(byte%4))
        for en in enums[asil]:
            data_list[asil].append("\""+en+"\","+str(byte)+","+str(bit))
            bit=bit+1
            if(bit >= 8):
                byte=byte+1
                bit=0

    with open(RootFolder+"/ErrorData.py","w") as file:
        for asil in FD56_PackedOrder_orderedList:
            file.write("ErrorData_"+asil+" = [ \n")
            for dat in data_list[asil]:
                file.write(("\t["+dat+"],\n"))
            file.write("]\n\n\n")

    return