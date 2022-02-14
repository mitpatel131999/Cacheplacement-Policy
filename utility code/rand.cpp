#include<bits/stdc++.h>
using namespace std;
#define WAY_ASS 64
#define SET_ 1024
#define BLOCK_SIZE 64
#define CACHE_SIZE SET_*WAY_ASS*BLOCK_SIZE
#define CACHE_LINE SET_*WAY_ASS
#define MAXTRACELINESIZE 64
double Alpha=1;

unsigned long long TimeStamp=101;

vector< vector<unsigned long long> > Memory(SET_,vector<unsigned long long> (WAY_ASS,0));

vector< pair<unsigned long long,double > > History(1<<26,{3,INT_MAX});

unsigned long long Update_History(unsigned long long SET,unsigned long long Address);

unsigned long long Find_Victam(unsigned long long SET,unsigned long long Address)
    {
    	/*vector<pair<int,int>> tamp(WAY_ASS,{0,0});
    	for(int i=0;i<WAY_ASS;i++)
    	{
    		tamp[i]={History[Memory[SET][i]].first , i };
    		//if(History[Address].first + History[Address].second < TimeStamp)
			//{ Update_History(SET,Address);
			//}
		}
		
		sort(tamp.begin(),tamp.end());
	//	for(int i=0;i<tamp.size();i++){ cout<<tamp[i].first<<"-"<<tamp[i].second<<" "; } cout<<endl;
		*/
		return rand()%WAY_ASS;
		//return tamp[0].second;
     //	return 0;
    }
int Hit(unsigned long long SET,unsigned long long Address)
     {
	   for(int i=0;i<WAY_ASS;i++)
	   {
	   	if(Memory[SET][i]==Address){ return 1;}
	   }
	    return 0;
	 } 
	 
unsigned long long Update_History(unsigned long long SET,unsigned long long Address)
    {
	     double delay=TimeStamp > History[Address].first ? (double)(TimeStamp - History[Address].first): (double)(History[Address].first - TimeStamp);
	     double old=History[Address].second;
	     double new_delay=(double)delay*(Alpha) +(double)(((double)(1-Alpha))*(old));
	     //cout<<new_delay<<endl;
	     History[Address]={TimeStamp,INT_MAX};
	     return 0;
	}    
    
			                 

int main()
{
   fstream newfile;

   //newfile.open("face");
   
   FILE *fin;
   char newstr[MAXTRACELINESIZE];
    // Open both files, fail fast if either no good.

    if ((fin = fopen("face", "r")) == NULL) {
        fprintf(stderr, "Cannot read from input.txt");
        return 1;
    }
   
   long long TotalAccess=0;
   long long TotalInst=0;
   long long TotalHit=0;
   
   //for(int t=0;t<10000000; t++)
   while(true)
   {
     int x;
     char y;
     
	 /*string a,b;
	 unsigned long long p,q;
	 newfile>>x>>y>>a;
	 if(y=='R'){ newfile>>b;}
     //cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
     //cout<<a<<endl;
     a.resize( min( (int)a.size(), 10));
     a.resize(a.size()-2);
     p=std::stoull(a, nullptr, 16);
	// q=std::stoul(b, nullptr, 16);
   
    // unsigned long long Address=p/BLOCK_SIZE;
     */
	 int num;
	 char op;
	 long long int p;
	 long long int q;
	 if (fgets (newstr, MAXTRACELINESIZE,fin)>0)
     {
      if (sscanf (newstr, "%d %c", &num, &op) > 0)
      {
        if (op == 'R')
        {
          if (sscanf
              (newstr, "%d %c %Lx %Lx", &num,
               &op, &p, &q) < 1)
          {
            printf ("Panic.  Poor trace format.\n");
            return -4;
          }
        }
        else
        {
          if (op == 'W')
          {
            if (sscanf
                (newstr, "%d %c %Lx", &num,
                 &op, &p) < 1)
            {
              printf ("Panic.  Poor trace format.\n");
              return -3;
            }
          }
          else
          {
            printf ("Panic.  Poor trace format.\n");
            return -2;
          }
        }
      }
      else
	  { continue;
	  }
	  }
	  else
	  { break;
	  }
	  
	 TotalInst+=(num+1); 
	 unsigned long long Address=p/BLOCK_SIZE;
     
     unsigned long long Tag= Address/(CACHE_LINE);
     unsigned long long SET= Address % SET_;
    // cout<<Address<<" "<<SET<<endl;
     //cout<<SET<<" ";
     
     if(Hit(SET,Address))
	 {
	   TotalHit++;
	 }
	 else
	 {
		unsigned long long index=Find_Victam(SET,Address);
		//cout<<"\n INDEX"<<index<<endl;
	 	Memory[SET][index]=Address;
	 }
	 
	 Update_History(SET,Address);
	 TotalAccess++;
     TimeStamp++;
    /* 
     cout<<"\n\n\n";
	 for( int i=0;i<SET_;i++)
	 { for(int j=0;j<WAY_ASS;j++) 
	   { printf(" %8lld-%5lld",Memory[i][j],History[Memory[i][j]].first);
	   } cout<<endl;
	 }
	 cout<<"\n\n\n";*/
   }
 
  
   cout<<"\n HIT :"<<TotalHit<<"  \n rate: ";
   cout<<(double)(TotalHit)/(TotalAccess)<<"  %\n  Totel Access :"<<TotalAccess<<"\n miss per K is "<<double((TotalAccess-TotalHit)*1000)/TotalInst<<endl;
   return 0;
}
