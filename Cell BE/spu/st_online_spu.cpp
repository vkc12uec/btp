#include <stdio.h>
#include <string>
#include <vector>
#include <spu_mfcio.h>
#include <sys/time.h>

#define ROOT 0

using namespace std;

class Edge
{
      private:
          int beg_index;
          int end_index;
          int fromNode;
          int toNode;
      public:
          Edge(int beg, int end, int from, int to)
          {
                   beg_index = beg;
                   end_index = end;
                   fromNode = from;
                   toNode = to;
          }  
        friend class Node;
        friend class SuffixTree;
};


//Every node is a vector of edges that will lead us to the child nodes
//initially the vector will contain no elements
class Node
{
	private:
             vector<Edge> v;
             int Parent;
             int ParentEdge;
             int link;
			 char mark;//used in finding deepest fork
			 int count;//---do----
    
    public:
            Node(){ v.clear(); link = -1; Parent = -1; mark = 0; count = 0;}
            void Insert(Edge e)
            {
                v.push_back(e);
            }
            friend class SuffixTree;
};

/* TODO
    function for string update
*/
class SuffixTree
{
    private:
            int startlinkNode;	//stores the beginning of the link chain
            int max;            //max number of nodes
            int nodecount;      //current number of nodes other than root
            Node* arr;          //pool of nodes
            string str;          //string
            int str_len;        
			int maxcountnode;	//for deepest fork

            void OnlineUpdate(char c);
    public:
            SuffixTree(int maxNo, char* stringvalue)
            {
				maxcountnode = ROOT;
                str_len = 0;
                max=maxNo;
                arr=new Node[max];
                nodecount=0;
                InitializeTree(stringvalue);
            }
            SuffixTree(int maxNo)
            {
                str_len = 0;
                max=maxNo;
                arr=new Node[max];
                nodecount=0;
//                InitializeTree(stringvalue);
            }
            void InitializeTree(char* stringvalue)
            {
                int len = strlen(stringvalue);
                for(int i=0; i<len; ++i)
                {
                    publicOnlineUpdate(stringvalue[i]);
                }
            }
            
            void stringUpdate(char c)
            {
                str += c;
                str_len++;
            }
            int NodeAllocate()
            {
                  return ++nodecount;
            }

			void UpdateNodeMark(int currnode, char endmarker);

            void publicOnlineUpdate(char c)
            {
                stringUpdate(c);
                OnlineUpdate(c);
            }
            void DisplaySuffixes();
			void LongestCommonSubstring(unsigned int &beg, unsigned int &end);

			bool StringSearch(char* query, int qlen);

            int whoseFirstCharIs(int currnode, char c);
            void InsertNode(Edge& e, int mid);//mid value of string index where node is to be inserted
};

bool SuffixTree::StringSearch(char* query, int qlen) 
{
	printf("\nStringSearch.");

	int currnode = ROOT;
	int i=0;
    while(query[i]!='\0')
    {
//		cout<<"\nwhile";
		int j=0;
		for(j=0; j<arr[currnode].v.size(); j++)
		    if(str[arr[currnode].v[j].beg_index]==query[i]){
				i++;
				break;
			}
			
		if(j<arr[currnode].v.size())
		{
			if(arr[currnode].v[j].beg_index!=arr[currnode].v[j].end_index)
			{
//				cout<<"\nj update : "<<j;
				int tempindex = arr[currnode].v[j].beg_index+1;
				while(query[i]!='\0' && tempindex<=arr[currnode].v[j].end_index && str[tempindex]==query[i]){
					tempindex++;
					i++;
				}
//				cout<<"i : "<<i<<endl;
				if(i==qlen) return true;//str found
				else if(tempindex!=arr[currnode].v[j].end_index+1){
//					cout<<"\nMatched upto i : "<<i;
					return false;//str differs
				}
			}
			else if(query[i] == '\0')
				return true;
		}
		else
		{
//			cout<<"\nMatched upto i : "<<i;
			return false;
		}

		currnode = arr[currnode].v[j].toNode;
    }

	return false;
}

void SuffixTree::DisplaySuffixes()
{
//    printf("\nSPE Display\n");
/*     for(int p=0;p<=nodecount;p++)
     {
         for(int i=0; i<arr[p].v.size(); i++)
         {
             //for(int j=0,k=0; j<arr[k].v.size(); j++){
             if(arr[p].v[i].beg_index==str_len)printf("$");
             else
                 for(int k=arr[p].v[i].beg_index; k<=arr[p].v[i].end_index; k++)
                     printf("%c", str[k]);

             printf("(%i, %i)", arr[p].count, (int)(arr[p].mark));   
             printf("\t");
        }
        printf("\n");
     }*/
     printf("Number of children for node Root %i", arr[ROOT].v.size());
     printf("\nNumber of Nodes used in the program %i", nodecount);
     printf("\n\n");
}

void SuffixTree::LongestCommonSubstring(unsigned int &beg, unsigned int &end)
{
//	printf("\n(%i, %i)", arr[maxcountnode].count, (int)(arr[maxcountnode].mark));

/*	int currnode = maxcountnode, lastnode = ROOT;
	while(currnode != ROOT)
	{
		lastnode = currnode;
		currnode = arr[currnode].Parent;
	}*/
	if(maxcountnode != ROOT)
	{
//		printf("\nLCS : ");

		end = arr[arr[maxcountnode].Parent].v[arr[maxcountnode].ParentEdge].end_index;
		beg = end-arr[maxcountnode].count+1;

//		for(int i=arr[ROOT].v[arr[lastnode].ParentEdge].beg_index; i<=arr[arr[maxcountnode].Parent].v[arr[maxcountnode].ParentEdge].end_index; i++)
//			printf("%c", str[i]);
	}
//	else printf("\nInvalid");
}

//for updating mark and count values
void SuffixTree::UpdateNodeMark(int currnode, char endmarker)
{
	endmarker -= '0';
	char tempmarker = 0;
	for(int j=(int)endmarker; j>=1; j--)
		tempmarker = tempmarker | (1<<(j-1));
	endmarker = 1<<(endmarker-1);	
//	cout<<"\nsgjasags : "<<(int)tempmarker;
	arr[currnode].mark |= endmarker;
	while(currnode != ROOT)
	{
		currnode = arr[currnode].Parent;
		arr[currnode].mark |= endmarker;

		if(arr[currnode].mark == tempmarker && arr[maxcountnode].mark != tempmarker)
			maxcountnode = currnode;
		else if(arr[currnode].mark == tempmarker && arr[maxcountnode].mark == tempmarker && arr[currnode].count >= arr[maxcountnode].count)
			maxcountnode = currnode;
	}
}

void SuffixTree::OnlineUpdate(char c)
{
      if( arr[ROOT].v.size() == 0 )
      {
          Edge e(0, 0, ROOT, NodeAllocate()); //nodecount = 1;
          arr[ROOT].Insert(e);
          arr[nodecount].link = ROOT; 
          startlinkNode = nodecount;
          arr[nodecount].Parent = ROOT;
          arr[nodecount].ParentEdge = arr[ROOT].v.size() - 1;   //arr[arr[nodecount].Parent].v.size() - 1;
      }
      else //if( )//some condition
      {
          bool flag = true;
    	  int currNode = startlinkNode;
    	  int parentNode = -1;
    	  int lastNode = -1;
    	  //if( currNode == ROOT)
    	  //arr[currNode].v[0].end_index++;
    	  //else
    	  do{
//                cout<<"\nDO-While"<<endl;
    		  if(arr[currNode].v.size() == 0)		//only if leaf node increment the upper's edge
    		  {
//                  cout<<"\nLeaf\n";
                  parentNode = arr[currNode].Parent;
				  int temp = arr[parentNode].v[arr[currNode].ParentEdge].end_index;
    		      if(!(str[temp]>=48 && str[temp]<=57))
				  {
					arr[parentNode].v[arr[currNode].ParentEdge].end_index++;//for making genralized suffix tree
					arr[currNode].count++;//for app
					if(c>=48 && c<=57)
				  	{//for updating mark when c=endmarker
						UpdateNodeMark(currNode, c);
				  	}
				  }
    		      //ptr update
                  lastNode = currNode;
                  currNode = arr[currNode].link;
    		  }
    		  else //if(currNode == ROOT)		//when we reach ROOT traversing suffix links
    		  //non-leaf node
    		  {
//                    cout<<"\nNon-Leaf\n";
                    int temp_edge=-1;
                    if ( (temp_edge=whoseFirstCharIs(currNode, c)) != -1 )
                    {
                        bool size1 = false;
//                        cout<<"\nc found\n";
                        if( arr[currNode].v[temp_edge].beg_index != arr[currNode].v[temp_edge].end_index )
                        {   //split existing edge into 2
//                            cout<<"\nsplit\n";
                            
                            if(arr[currNode].v.size() == 1 && currNode != ROOT)
                            {
//                                cout<<"\n : "<<arr[currNode].ParentEdge<<"\n";
                                arr[arr[currNode].Parent].v[arr[currNode].ParentEdge].end_index++;
								arr[currNode].count++;//for app
                                arr[currNode].v[0].beg_index++;
                                
                                lastNode = currNode;
                                currNode = arr[currNode].link;
                                
                                size1 = true;
//                                cout<<"\nalshlas\n";
                            }
                            else
                            {
                                InsertNode( arr[currNode].v[temp_edge], arr[currNode].v[temp_edge].beg_index );
                            }
                            //ptr update
                            
                            
                        }
                        if(!size1)
                        {
                            arr[lastNode].link = arr[currNode].v[temp_edge].toNode;
                            
                            if (arr[currNode].link == -1)
							{//matlab ki ye root hai
                                arr[arr[currNode].v[temp_edge].toNode].link = ROOT;
                                
                                lastNode = arr[currNode].v[temp_edge].toNode;
                                currNode = ROOT;    //arr[arr[currNode].v[temp_edge].toNode].link
                                
                                flag = false;//done
                            }
                            else
                            { 
                                arr[arr[currNode].v[temp_edge].toNode].link = arr[currNode].link;
                                arr[currNode].link = -1;//out of chain
                                lastNode = arr[currNode].v[temp_edge].toNode;         
                                currNode = arr[lastNode].link;
                            }
                        }
                    }
                    else if((c<48 || c>57) || currNode!=ROOT)//b/c we dont want any new edge at root starting with end marker
                    {//new edge
//changed to run on spu
//                        cout<<"\nNew Edge\n";
                        if(currNode == ROOT)
                        {
/*                            arr[lastNode].link = e.toNode;
                            arr[new_node].link = ROOT;
                            lastNode = arr[lastNode].link;*/
                            flag = false;
                        }
						else
						{
	                        int new_node = NodeAllocate();
	                        Edge e( str_len-1, str_len-1, currNode, new_node );
	                        arr[currNode].Insert(e);
	                        arr[new_node].Parent = currNode;
	                        arr[new_node].ParentEdge = arr[arr[new_node].Parent].v.size()-1;
							arr[new_node].count = arr[arr[new_node].Parent].count + (e.end_index-e.beg_index+1);//for app                        

//                        else
//                        {
							if(c>=48 && c<=57) UpdateNodeMark(currNode, c);//update if c=endmarker
                            arr[lastNode].link = e.toNode;
                            arr[new_node].link = arr[currNode].link;
                            arr[currNode].link = -1;
                            lastNode = new_node;
                            currNode = arr[new_node].link;
                        }
                    }
					else//if str[end_index]=end marker
					{
						lastNode = currNode;
						if(currNode == ROOT)flag=false;
						else currNode = arr[currNode].link;
					}
    			    //InsertNode( arr[ROOT].v[ whoseFirstCharis(currNode,c) ] , 0);
    		  }
    		  //lastNode = currNode;  already done
    		  //currNode = arr[currNode].link;
    		  
    	  }while( flag );
      }
}

void SuffixTree::InsertNode(Edge& e, int mid)//, int next, int last)
{
      int temp_end_index = e.end_index;
      e.end_index=mid;
      int node_1 = NodeAllocate();
      Edge lower(mid+1, temp_end_index, node_1, e.toNode);
      arr[node_1].Insert(lower);
      

//      arr[e.toNode].ParentEdge = arr[arr[e.toNode].Parent].v.size() - 1;


      arr[node_1].ParentEdge = arr[e.toNode].ParentEdge;//arr[arr[nodecount].Parent].v.size() - 1;
      arr[e.toNode].ParentEdge = 0;//arr[arr[e.toNode].Parent].v.size() - 1;

      arr[e.toNode].Parent = node_1;      
      arr[node_1].Parent = e.fromNode;
      e.toNode = node_1;

	  arr[node_1].count = arr[arr[node_1].Parent].count + (e.end_index-e.beg_index+1);
	  arr[node_1].mark = arr[lower.toNode].mark;      
}

int SuffixTree::whoseFirstCharIs(int currnode, char c)		//returns the edge index in the currnode's edgevector whose first character is c;
{
//     cout<<"\nWhoseFirstChar\n";
	 int i=0;
//	 cout<<endl<<arr[currnode].v.size();
	 while(i < arr[currnode].v.size() )
	 {
		 if( str[ arr[currnode].v[i].beg_index ] == c )
             return i;
		++i;
	 }
	 return -1;
}

int main()
{
	SuffixTree s(1700);
	char ch;
	int id;
	//spe reading from ppe

	do {
       unsigned int data = 0;
       while(!spu_stat_in_mbox());
       data = spu_read_in_mbox();
       ch = (char)data;
		if(ch == 'D')
		{
			printf("\nDisplay SPE %d\n", id);
			s.DisplaySuffixes();
		}
		else if(ch == 'X')
		{
	        data = 9;// to indicate recv. of X
	        while(!spu_stat_out_mbox());
	        spu_write_out_mbox(data);

	        while(!spu_stat_in_mbox());
	        data = spu_read_in_mbox();
			int size = (int)data;
			char* searchstr = new char [size];

	        data = 9;// to indicate recv. of searchstr len
	        while(!spu_stat_out_mbox());
	        spu_write_out_mbox(data);

			for(int i=0; i<size; i++)
			{
		        while(!spu_stat_in_mbox());
		        data = spu_read_in_mbox();
		        searchstr[i] = (char)data;				

		        data = 9;// to indicate recv. of searchstr
		        while(!spu_stat_out_mbox());
		        spu_write_out_mbox(data);
			}
			searchstr[size] = '\0';
			printf("\nSPE %d\n", id);
			if(s.StringSearch(searchstr, size))printf("\nTrue");
			else printf("\nFalse");
			delete [] searchstr;

		}
		else if(ch == 'L')
		{
	        data = 9;// to indicate recv. of L
	        while(!spu_stat_out_mbox());
	        spu_write_out_mbox(data);

//			printf("\nSPE %d\n", id);

			unsigned int beg, end;
			s.LongestCommonSubstring(beg, end);
			//send
			data = beg;
			while(!spu_stat_out_mbox());
		    spu_write_out_mbox(data);

			while(!spu_stat_in_mbox());
	        data = spu_read_in_mbox();
			if(data!=9)printf("\nError");

			data = end;
			while(!spu_stat_out_mbox());
		    spu_write_out_mbox(data);

			while(!spu_stat_in_mbox());
	        data = spu_read_in_mbox();
			if(data!=9)printf("\nError");

		}
		else if(data>=10 && data <=14)
		{
			id = data-10;
		}
		else if (ch != 'Z')
			s.publicOnlineUpdate(ch);
		
		//spe work done
		//spe giving to ppe
        data = 9;// to indicate work done
        while(!spu_stat_out_mbox());
        spu_write_out_mbox(data);
	}while(ch != 'Z');
    
	printf("\nBye!");

	return 0;
}
