#include <libspe.h>
#include <stdio.h>
#include <string>
#include <sys/wait.h>

#define SPU_THREADS 8

using namespace std;

extern spe_program_handle_t st_online_spu;

int main() 
{
	speid_t spe_id[SPU_THREADS];
	int i;
	int threads[2]={0};
	for(i=0; i<SPU_THREADS;i++)
	   spe_id[i] = spe_create_thread(0,&st_online_spu, NULL, NULL, -1, 0);

//	char AGCT[4] = {'M', 'S', 'I', 'P'};
	char AGCT[4] = {'A', 'G', 'C', 'T'};
	bool livechar[2][4];	//A0 G1 C2 T3
	for(int j=0; j<2; j++)
		for(int i=0; i<4; i++)
			livechar[j][i] = false;
    unsigned int data[2];


	char str[2][1600] = {"ATGGTTCCAGCTTTGTTCTTTTGGCTTAGGATTGACTTGGCAATGTGGGCTCTTTTTTGGTTCCATATGAACTTTAAAGTAGTTTTTTCCAATTCTGTGAAGAAATTCATTGGTAGCTTGATGGGGATGGCATTGAATCTATAAATTACCCTGGGCAGTATGGCCATTTTCACAATATTGAATCTTCCTACCCATGAGCGTGTACTGTTCTTCCATTTGTTTGTATCCTCTTTTATTTCATTGAGCAGTGGTTTGTAGTTCTCCTTGAAGAGGTCCTTCACATCCCTTGTAAGTTGGATTCCTAGGTATTTTATTCTCTTTGAAGCAATTGTGAATGGGAGTTCACTCATGATTTGACTCTCTGTTTGTCTGTTATTGGTGTATAAGAATGCTTGTGATTTTTGCACATTGATTTTGTATCCTGAGACTTTGCTGAAGTTGCTTATCAGCTTAAGGAGATTTTGGGCTGAGACGATGGGGTTTTCTAGATATACAATCATGTCATCTGCAAACAGGGACAATTTGACTTCCTCTTTTCCTAATTGAATACCCGTTATTTCCCTCTCCTGCCTGATTGCCCTGGCCAGAACTTCCAACACTATGTTGAATAGGAGTGGTGAGAGAGGGCATCCCTGTCTTGTGCCAGTTTTCAAAGGGAATGCTTCCAGTTTTTGTCCATTCAGTATGATATTGGCTGTGGGTTTGTCATAGATAGCTCTTATTATTTTGAGATACATCCCATCAATACCTAATTTATTGAGAGTTTTTAGCATGAAGAGTTCTTGAATTTTGTCAAAGGCCTTTTCTGCATCTTTTGAGATAATCATGTGGTTTCTGTCTTTGGTTCTGTTTATATGCTGGAGTACGTTTATTGATTTTCGTATGTTGAACCAGCCTTGCATCCCAGGGATGAAGCCCACTTGATCATGGTGGATAAGCTTTTTGATGTGCTGCTGGATTCGGTTTGCCAGTATTTTATTGAGGATTTCTGCATCGATGTTCATCAAGGATATTGGTCTAAAATTCTCTTTTTTTGTTGTGTCTCTGTCAGGCTTTGGTATCAGGATGATGCTGGCCTCATAAAATGAGTTAGGACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAACGCTAGCTAGCTAGCAGCCTAAGCTAGTCAGCTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGAAGTCGATC1DXLZ", "AGGGTACATGTGCACAACGTGCAGGTTTGTTACATATGTATACACGTGCCATGATGGTGTGCTGCACCCATTAACTCGTCATTTAGCGTTAGGTATATCTCCGAATGCTATCCCTCCCCCCTCCCCCCACCCCACAACAGTCCCCGGTGTGTGATGTTCCCCTTCCTGTGTCCATGTGTTCTCATTGTTCAATTCCCACCTATGAGTGAGAACATGCGGTGTTTGGTTTTTTGTCCTTGCGAAAGTTTGCTGAGAATGATGGTTTCCAGCTTCATCCATATCCCTACAAAGGACATGAACTCATCATTTTTTTATGGCTGCATAGTATTCCATGGTGTATATGTGCCACATTTTCTTAACCCAGTCTACCCTTGTTGGACATCTGGGTTGGTTCCAAGTCTTTGCTATTGTGAATAGTGCCGCAATAAACATACGTGTGCATGTGTCTTTATAGCAGCATGATTTATAATCCTTTGGGTATATACCCAGTAATGGGATGGCTGGGTCAAATGGTATTTCTAGTTCTAGATCCCTGAGGAATCACCACACTGACTTCCACAATGGTTGAACTAGTTTACAGTCCCAGCAACAGTTCCTATTTCTCCACATCCTCTCCAGCACCTGTTGTTTCCTGACTTTTTAATGATCGCCATTCTAACTGGTGTGAGATGGTATCTCATTGTGGTTTTGATTTGCATTTCTCTGATGGCCAGTGATGATGAGCATTTTTTCATGTGTTTTTTGGCTGCATAAATGTCTTCTTTTGAGAAGTGTCTGTTCATATCCTTCGCCCACTTTTGATGGGGTTGTTTGTTTTTTTCTTGTAAATTTGTTGGAGTTCATTGTAGATTCTGGGTATTAGCCCTTTGTCAGATGAGTAGGTTGCAAAAATTTTCTCCCATTCTGTAGGTTGCCTGTTCACTCTGATGGTGGTTTCTTCTGCTGTGCAGAAGCTCTTTAGTTTAATTAGATCCCATTTGTCAATTTTGGCTTTTGTTGCCATAGCTTTTGGTGTTTTAGACATGAAGTCCTTGCCCATGCCTATGTCCTGAATGGTATTGCCTAGGTTTTCTTCTAGGGTTTTTATGGTTTTAGGTCTAACATGTAAGTCTTTAATCCATCTTGAATTAATTATAAGGTGTATATTATAAGGTGTAATTATAAGGTGTATAATTATATATTAATTATAAGGTGTATATTAATTATAAGGTGTAAGGAAGGGATCCAGTTTCAGCTTTCTACATATGGCTAGCCAGTTTTCCCTGCACCATTTATTAAATAGGGAATCCTTTCCCCATTGCTTGTTTTTGTCAGGTTTGTCAAAGATCAGATAGTTGTAGATATGCGGCATTATTTCTGAGGGCTCTGTTCTGTTCCATTGGTCTATATCTCTGTTTTGGTACCAGTACCATGCTGTTTTGGTTACTGTAGCCTTGTAGTATAGTTTGAAGTCAGGTAGCGTGATGGTTCCAGCTTTGTTCTTTTGGCTTAGGATTGACTTGGCAATGTGGGCTCTTTTTTGGTTCCATATGAACTTTAAAGTAGTTTTTTCCAATTCTGTGAAGAAATTCATTGGTAGCTTGATGGGGATGGC1DXLZ"};

	unsigned int start[2][4];


	char searchstr[][4][100] = {{"ACTTTCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTAAGCTAG", "GCTACGATCAGCTAGCTAGCATACGT", "CTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACB", "TAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTTCGATCGACTAACGTACTTB"}, {"ACGGCCACCGCTGCCCTGCCCCTGGAGG", "GTCCCCCGGC", "CGGCCTCCTGCTGCT", "TGGAGGGTGGCCCCACC"}};



	int str_len = strlen(str[0]);
	int str_len2 = strlen(str[1]);

//	printf("\nstr1 :%i, str2 :%i\n", str_len, str_len2);

	int largerstr=1;
	if(str_len > str_len2)
	{
		largerstr=0;
		//swap
		str_len = str_len ^ str_len2;
		str_len2 = str_len ^ str_len2;
		str_len = str_len ^ str_len2;
	}

//	printf("\nstr1 :%i, str2 :%i\n", str_len, str_len2);

//	do
//	{
	int p=0;
	for(i=0; i<str_len; i++)
	{
/*		for(p=0; p<2; p++)
		{*/
//		p=0;
//		data[p] = (unsigned int)(str[p][i]);	//character to be casted to int to be sent to spe's
		if(threads[0]<4 && threads[1]<4)
		{
			for( int j=0; j<SPU_THREADS; j++)
			{
				p = j/4;
				if( str[p][i] == AGCT[j%4] && livechar[p][j%4] == false )
				{
//					printf("\nFalse %i %c\n", j, str[i]);
					livechar[p][j%4] = true;//activate the req spe
					start[p][j%4] = i;

					//send char to one new thread
					data[p] = 10 + (threads[p])++;
					while(!spe_stat_in_mbox(spe_id[j]));
  	    			spe_write_in_mbox(spe_id[j], data[p]);

 					while(!spe_stat_out_mbox(spe_id[j]));
				    data[p] = spe_read_out_mbox(spe_id[j]);
		    	    if(data[p] != 9) printf("\nError");
				}
	 			if( livechar[p][j%4] == true )
				{
					data[p] = (unsigned int)(str[p][i]);
//					printf("\nTrue %i %c\n", j, (char)data);
					while(!spe_stat_in_mbox(spe_id[j]));
  	    			spe_write_in_mbox(spe_id[j], data[p]);

				    while(!spe_stat_out_mbox(spe_id[j]));
				    data[p] = spe_read_out_mbox(spe_id[j]);
				    if(data[p] != 9) printf("\nError");
				}
			}
		}
		else
		{
//			printf("\nelse\n");
			for(int j=0; j<SPU_THREADS; j++)
			{
				p = j/4;
			    data[p] = (unsigned int)(str[p][i]);
				while(!spe_stat_in_mbox(spe_id[j]));
    			spe_write_in_mbox(spe_id[j], data[p]);
			}
			for(int j=0; j<SPU_THREADS; j++)
			{
				p = j/4;
			    while(!spe_stat_out_mbox(spe_id[j]));
			    data[p] = spe_read_out_mbox(spe_id[j]);
			    if(data[p] != 9) printf("\nError");
			}
			if(str[0][i]=='X' || str[1][i]=='X')
			{
				int begi=0, endi=0;
				if(str[0][i]=='X' && str[1][i]=='X'){begi=0;endi=8;}
				else if(str[0][i]=='X'){begi=0;endi=4;}
				else {begi=4;endi=8;}
				for(int k=begi; k<endi; k++)
				{
					p=k/4;
					int size = strlen(searchstr[p][k%4]);

					data[p] = (unsigned int)size;
					while(!spe_stat_in_mbox(spe_id[k]));
	    			spe_write_in_mbox(spe_id[k], data[p]);

				    while(!spe_stat_out_mbox(spe_id[k]));
				    data[p] = spe_read_out_mbox(spe_id[k]);
				    if(data[p] != 9) printf("\nError");

					for(int j=0; j<size; j++)
					{
					    data[p] = (unsigned int)(searchstr[p][k%4][j]);
						while(!spe_stat_in_mbox(spe_id[k]));
		    			spe_write_in_mbox(spe_id[k], data[p]);

					    while(!spe_stat_out_mbox(spe_id[k]));
					    data[p] = spe_read_out_mbox(spe_id[k]);
					    if(data[p] != 9) printf("\nError");
					}
				}
				for(int k=begi; k<endi; k++)
				{
					p=k/4;
				    while(!spe_stat_out_mbox(spe_id[k]));
				    data[p] = spe_read_out_mbox(spe_id[k]);
				    if(data[p] != 9) printf("\nError");
				}
			}
			else if(str[0][i]=='L' || str[1][i]=='L')
			{
//				printf("\nL1");
				int begi=0, endi=0;
				if(str[0][i]=='L' && str[1][i]=='L'){begi=0;endi=8;p=0;}
				else if(str[0][i]=='L'){begi=0;endi=4;p=0;}
				else {begi=4;endi=8;p=1;}

				int begindex[2][4], endindex[2][4], bestspe=0, maxsize=0;
				for(int k=begi; k<endi; k++)
				{	//recv
					p=k/4;
				    while(!spe_stat_out_mbox(spe_id[k]));
				    data[p] = spe_read_out_mbox(spe_id[k]);
					begindex[p][k%4] = (int)data[p] + start[p][k%4];

				    data[p] = 9;
					while(!spe_stat_in_mbox(spe_id[k]));
	    			spe_write_in_mbox(spe_id[k], data[p]);

				    while(!spe_stat_out_mbox(spe_id[k]));
				    data[p] = spe_read_out_mbox(spe_id[k]);
					endindex[p][k%4] = (int)data[p] + start[p][k%4];

				    data[p] = 9;
					while(!spe_stat_in_mbox(spe_id[k]));
	    			spe_write_in_mbox(spe_id[k], data[p]);

//					printf("\nPPU beg %i, end %i", begindex[k], endindex[k]);

					if(maxsize < (endindex[p][k%4]-begindex[p][k%4]))
					{
						maxsize = endindex[p][k%4]-begindex[p][k%4];
						bestspe = k%4;
					}
				}
//				printf("\nL2");
				for(int k=begi; k<endi; k++)
				{
					p=k/4;
				    while(!spe_stat_out_mbox(spe_id[k]));
				    data[p] = spe_read_out_mbox(spe_id[k]);
				    if(data[p] != 9) printf("\nError");
				}
				printf("\nLCS : ");
				for(int j=begindex[p][bestspe]; j<=endindex[p][bestspe]; j++)
					printf("%c", str[p][j]);
				printf("\n");
				if(str_len == str_len2)
				{
					for(int j=begindex[1-p][bestspe]; j<=endindex[1-p][bestspe]; j++)
						printf("%c", str[1-p][j]);
					printf("\n");
				}
			}
		}
//		}
	}

//for leftover str
	p = largerstr;
//	printf("\ni : %i : %i : %i\n", str_len, str_len2, p);	
	for(i=str_len; i<str_len2; i++)
	{
//		printf("\ni : %i\n", i);
		data[p] = (unsigned int)(str[p][i]);	//character to be casted to int to be sent to spe's
		if(threads[p]<4)
		{
//			printf("\nye kya ho raha hai!");
			for( int j=0; j<4; j++)
			{
				if( str[p][i] == AGCT[j] && livechar[p][j] == false )
				{
//					printf("\nFalse %i %c\n", j, str[i]);
					livechar[p][j] = true;//activate the req spe
					start[p][j] = i;

					//send char to one new thread
					data[p] = 10 + (threads[p])++;
					while(!spe_stat_in_mbox(spe_id[j+4*p]));
  	    			spe_write_in_mbox(spe_id[j+4*p], data[p]);

 					while(!spe_stat_out_mbox(spe_id[j+4*p]));
				    data[p] = spe_read_out_mbox(spe_id[j+4*p]);
		    	    if(data[p] != 9) printf("\nError");
				}
	 			if( livechar[p][j] == true )
				{
					data[p] = (unsigned int)(str[p][i]);
//					printf("\nTrue %i %c\n", j, (char)data);
					while(!spe_stat_in_mbox(spe_id[j+4*p]));
  	    			spe_write_in_mbox(spe_id[j+4*p], data[p]);

				    while(!spe_stat_out_mbox(spe_id[j+4*p]));
				    data[p] = spe_read_out_mbox(spe_id[j+4*p]);
				    if(data[p] != 9) printf("\nError");
				}
			}
		}
		else
		{
//			printf("\nelse\n");
			for(int j=0; j<4; j++)
			{
			    data[p] = (unsigned int)(str[p][i]);
				while(!spe_stat_in_mbox(spe_id[j+4*p]));
    			spe_write_in_mbox(spe_id[j+4*p], data[p]);
			}
			for(int j=0; j<4; j++)
			{
			    while(!spe_stat_out_mbox(spe_id[j+4*p]));
			    data[p] = spe_read_out_mbox(spe_id[j+4*p]);
			    if(data[p] != 9) printf("\nError");
			}
			if(str[p][i]=='X')
			{
				for(int k=0; k<4; k++)
				{
					int size = strlen(searchstr[p][k]);

					data[p] = (unsigned int)size;
					while(!spe_stat_in_mbox(spe_id[k+4*p]));
	    			spe_write_in_mbox(spe_id[k+4*p], data[p]);

				    while(!spe_stat_out_mbox(spe_id[k+4*p]));
				    data[p] = spe_read_out_mbox(spe_id[k+4*p]);
				    if(data[p] != 9) printf("\nError");

					for(int j=0; j<size; j++)
					{
					    data[p] = (unsigned int)(searchstr[p][k][j]);
						while(!spe_stat_in_mbox(spe_id[k+4*p]));
		    			spe_write_in_mbox(spe_id[k+4*p], data[p]);

					    while(!spe_stat_out_mbox(spe_id[k+4*p]));
					    data[p] = spe_read_out_mbox(spe_id[k+4*p]);
					    if(data[p] != 9) printf("\nError");
					}
				}
				for(int k=0; k<4; k++)
				{
					    while(!spe_stat_out_mbox(spe_id[k+4*p]));
					    data[p] = spe_read_out_mbox(spe_id[k+4*p]);
					    if(data[p] != 9) printf("\nError");
				}
			}
			else if(str[p][i]=='L')
			{
				int begindex[4], endindex[4], bestspe=0, maxsize=0;
				for(int k=0; k<4; k++)
				{	//recv
				    while(!spe_stat_out_mbox(spe_id[k+4*p]));
				    data[p] = spe_read_out_mbox(spe_id[k+4*p]);
					begindex[k] = (int)data[p] + start[p][k];

				    data[p] = 9;
					while(!spe_stat_in_mbox(spe_id[k+4*p]));
	    			spe_write_in_mbox(spe_id[k+4*p], data[p]);

				    while(!spe_stat_out_mbox(spe_id[k+4*p]));
				    data[p] = spe_read_out_mbox(spe_id[k+4*p]);
					endindex[k] = (int)data[p] + start[p][k];

				    data[p] = 9;
					while(!spe_stat_in_mbox(spe_id[k+4*p]));
	    			spe_write_in_mbox(spe_id[k+4*p], data[p]);

//					printf("\nPPU beg %i, end %i", begindex[k], endindex[k]);

					if(maxsize < (endindex[k]-begindex[k]))
					{
						maxsize = endindex[k]-begindex[k];
						bestspe = k;
					}
				}
				for(int k=0; k<4; k++)
				{
				    while(!spe_stat_out_mbox(spe_id[k+4*p]));
				    data[p] = spe_read_out_mbox(spe_id[k+4*p]);
				    if(data[p] != 9) printf("\nError");
				}
				printf("\nLCS : ");
				for(int j=begindex[bestspe]; j<=endindex[bestspe]; j++)
					printf("%c", str[p][j]);
				printf("\n");
			}
		}
	}
	return 0;
}

//diff test cases
/*
	char x = fgetc(stdin);
	printf("\nhey %c", x);
*/

//	char str[2][1300] = {"AGCTACGATCAGCTAGCTAGCATACGTACTTTCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCCTAAGCTAGTCAGCTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCAGCCTAAGCTAGTCAGCTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGAAGCCTAAGCTAGTCAGCTTAAGAGCCTAAGCTAGTCAGCTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCCTAAGCTAGTCAGCTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCAGCCTAAGCTAGTCAGCTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTTCGATCGACTAACGTACTT1DXLZ", "ACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACCTACGATCAGCTAGCTAGCATACGTACTTAAGCTAGCTAGCTAGCTAGCTAGCTAGGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGAGCTCGGGAGGGCCAGGCGGCAGGAAGGCGCCCCCCCAGCAATCCGCGCGCCGGGACAGAACCCTGCAGGAACTTCTTCTGGAAGACCTTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAACCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAA1ATACGTACTTTCGATCGACTAGCTACGATCAGCTAGCTAGCATACGTACTTAAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCATCGATCAGCTCGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAAGTCGATCGATCGACTAGCTACGATCAGCCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGACAATAGCTAGCATACGTACTCTAGCTAGCCTAAGCTAGTCCATTGTCCCCCGGCCTCCTGCAGTCGATGCTGGATGCTAGCTGATCGATCGATCGATCGATCGAGCTAGCGTTGAGCTGAGAGCCTAGGCTAGCTAGCTAGCTAGCTACATGCTGCTGCTCTCCGGGGACAA2DXLZ"};

//	char searchstr[][4][50] = {{"AGATGCCATTGTCCCCC", "GTCCCCCGGCCTCCTGCTGCTG", "CTCCGGGGCCACGGCCACCGCTGCCCTGCC", "TCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCAC"}, {"AGCATATGCAGGAAGCGG", "GCAGGAAGCGGCAGGAATAAGG", "CATATGCAGGAAGCGGCAGGAATAAGGAAAAG", "TGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATA"}};

//	char str[2][50] = {"MISSISSIPPI1DXLZ", "MISSISSIPPI1IPPISSISSIM2DXLZ"};
//	char searchstr[][4][15] = {{"MISSISSIP", "SSISSIPI", "ISSISSIP", "P"}, {"MISSISS", "SSISSIPPI", "ISSISSIPPI", "PPI"}};

/*	char str[2][100] = {"ACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCACCGCTGCCCTGCC1DXLZ", "CCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGC1DXLZ"};

	char searchstr[][4][50] = {{"AGATGCCATTGTCCCCC", "GTCCCCCGGCCTCCTGCTGCTG", "CTCCGGGGCCACGGCCACCGCTGCCCTGCC", "TCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCAC"}, {"AGCATATGCAGGAAGCGG", "GCAGGAAGCGGCAGGAATAAGG", "CATATGCAGGAAGCGGCAGGAATAAGGAAAAG", "TGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATA"}};
*/

