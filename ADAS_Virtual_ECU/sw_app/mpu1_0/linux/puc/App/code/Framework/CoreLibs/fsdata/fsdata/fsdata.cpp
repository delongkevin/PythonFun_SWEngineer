/*
 * fsdata.c
 *
 *  Created on: 08-Mar-2023
 *      Author: sagasast@magna.global
 */

#include "fsdata.h"
#include <osal/io/File.h>
#include <osal/io/InOut.h>
#include <osal/io/MemoryFile.h>
#include <stdint.h>
#include <osal/threading/Mutex.h>

namespace fsdata
{

#define ETFS_MAX_DATA_WRITE_SIZE	512
#define RETRY_MAX_COUNT				4

osal::Mutex mutex_o;
// --------------------------------------------------------------------------
/// @brief Function stores the data at specified path using filename
///
/// Function stores the data at specified path using filename
///
/// @param[in]  filename  	Name of the file including path
/// @param[in]  data     	data to store at filename path
/// @param[in]  size    	size of the datatype to be store
/// @return     bool		return result from function
// --------------------------------------------------------------------------

bool fsdata_store_data(const char *filename,const char *data,int size)
{
	int blocksize = 0;

	uint32_t file_chunks_to_write_l=0;
	uint32_t chunk_size_to_write_l = 0;
	uint32_t i = 0;
	uint32_t index_l=0;
	uint8_t retry_cnt =0;
	uint32_t write_ret_val_l = 0;
	bool ret = false;
	uint32_t bytes_in_last_chunk_l = 0;

	mutex_o.take_b();
	file_chunks_to_write_l = (size/ETFS_MAX_DATA_WRITE_SIZE);
	chunk_size_to_write_l = ETFS_MAX_DATA_WRITE_SIZE;
	if(bytes_in_last_chunk_l = (size%ETFS_MAX_DATA_WRITE_SIZE))
	{
		file_chunks_to_write_l += 1;
	}
	printf("%s: write with size %ld is divided into %d chunks\n",filename,size,file_chunks_to_write_l);

	FILE *fd = fopen(filename, "w+");
	if (fd)
	{
		for(i = 0; i < (file_chunks_to_write_l);i++)
		{
			if(i == (file_chunks_to_write_l-1))	//if this is the last chunk then size should remained bytes
			{
				if(bytes_in_last_chunk_l != 0)
				{
					chunk_size_to_write_l = bytes_in_last_chunk_l;
				}
				printf("%s: writing last chunk of data\n",filename);
			}

			index_l = i*ETFS_MAX_DATA_WRITE_SIZE;
			retry_cnt = 0;
			do{
				write_ret_val_l = fwrite(data+(i*ETFS_MAX_DATA_WRITE_SIZE), 1, chunk_size_to_write_l, fd);
				if(write_ret_val_l != chunk_size_to_write_l)
				{
					retry_cnt++;
					printf("%s: file chunk %d, index: %d write with element size : %d, retry_cnt: %d !!!\n",filename,i,index_l,chunk_size_to_write_l,retry_cnt);
					fclose(fd);
					fd = fopen(filename, "a+");
					ret = false;
				}
				else
				{
					ret = true;
				}
			}while((retry_cnt < RETRY_MAX_COUNT) && (write_ret_val_l == 0));
			if(retry_cnt >= RETRY_MAX_COUNT)
			{
				printf("%s: file write failed !!!\n",filename);
				ret = false;
				break;
			}
			if(i == 0)
			{
				fclose(fd);
				fd = fopen(filename, "a+");	//open the file in append mode now onward
			}
		}
	}
	fclose(fd);

	mutex_o.give_v();
	return ret;
}


// --------------------------------------------------------------------------
/// @brief Function reads the data at specified path using filename
///
/// Function stores the data at specified path using filename
///
/// @param[in]  filename  	Name of the file including path
/// @param[in]  data     	data to read from filename path
/// @return     bool		return result from function
// --------------------------------------------------------------------------

bool fsdata_read_data(const char *filename,char *data,int size)
{
	int blocksize = 0;

	uint32_t file_chunks_to_read_l=0;
	uint32_t chunk_size_to_read_l = 0;
	uint32_t i = 0;
	uint32_t index_l=0;
	uint8_t retry_cnt =0;
	uint8_t read_ret_val_l = 0;
	bool ret = false;
	uint32_t bytes_in_last_chunk_l = 0;

	mutex_o.take_b();
	file_chunks_to_read_l = (size/ETFS_MAX_DATA_WRITE_SIZE);
	chunk_size_to_read_l = ETFS_MAX_DATA_WRITE_SIZE;
	if(bytes_in_last_chunk_l = (size%ETFS_MAX_DATA_WRITE_SIZE))
	{
		file_chunks_to_read_l += 1;
	}
	printf("%s: read with size %ld is divided into %d chunks\n",filename,size,file_chunks_to_read_l);

	FILE *fd = fopen(filename, "r");
	if (fd)
	{
		for(i = 0; i < (file_chunks_to_read_l);i++)
		{
			if(i == (file_chunks_to_read_l-1))	//if this is the last chunk then size should remained bytes
			{
				if(bytes_in_last_chunk_l != 0)
				{
					chunk_size_to_read_l = bytes_in_last_chunk_l;
				}
				printf("%s: reading last chunk of data\n",filename);

			}
			index_l = i*ETFS_MAX_DATA_WRITE_SIZE;
			retry_cnt = 0;
			do{
				read_ret_val_l =fread(&data[index_l], chunk_size_to_read_l,1, fd);
				if(read_ret_val_l == 0)
				{
					retry_cnt++;
					printf("%s: file chunk %d, index: %d read with element size : %d, retry_cnt: %d !!!\n",filename,i,index_l,chunk_size_to_read_l,retry_cnt);
					fclose(fd);
					fd = fopen(filename, "r");
					ret = false;
				}
				else
				{
					ret = true;
				}
			}while((retry_cnt < RETRY_MAX_COUNT) && (read_ret_val_l == 0));
			if(retry_cnt >= RETRY_MAX_COUNT)
			{
				printf("%s: file read failed !!!\n",filename);
				ret = false;
				break;
			}
		}
	}
	fclose(fd);

	mutex_o.give_v();
	return ret;
}
}




























