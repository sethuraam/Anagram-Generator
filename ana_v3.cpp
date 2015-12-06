#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
struct node
{
	char *data=new char[10000];
	struct node *next;
}*head[26];

void clear_head()
{
	for(int i=0;i<26;i++)
	{
		//head[i]=new node;
	head[i]=NULL;
	}

}
node* insert(node *head,char *s)
{
	struct node *temp;
	temp=new node;
	strcpy(temp->data,s);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}

	else
	{
		struct node *s,*r;

		if(strcmp(temp->data,head->data)<0)
		{
			temp->next=head;
			head=temp;
		}
		if(strcmp(temp->data,head->data)==0)
		return head;
		else
		{
			s=head;
			int flag=1;
			while(strcmp(temp->data,head->data)>0)
				{
					r=s;
					if(s->next!=NULL)
					s=s->next;
					if(s->next==NULL)
					{
						flag=0;
						break;
					}
				}
			if(flag)
			{
				r->next=temp;
				temp->next=s;
			}
			else
			{
				s->next=temp;

			}
		}
	}
	return head;
}

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void generate(char *a, int i, int n)
{
	char word[50];

	int k=0;
   int j;

   if (i == n)
   {
   	 int arr=*a-97;
   	head[arr]=insert(head[arr],a);
   }

   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          generate(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}

void traversal(char *w)
{
	int found=0;
//	string word;
	for(int i=0;i<26;i++)
	{
		node *s=head[i];
		if(s==NULL)
		{
		continue;
		}
		else
		{
		char text=i+97;
		char name[6],str[100];
		name[0]=text;
		name[1]='.';
		name[2]='t';
		name[3]='x';
		name[4]='t';
		name[5]='\0';
        while(s!=NULL)
        {
            ifstream file(name);
            while(file >> str)
            {
            //	cout<<"Anagrams : ->  ";
            //	cout<<s->data<<" ";
                if(strcmp(str,s->data)==0)
                {
                if(strcmp(str,w)!=0)
                {
                    found=1;
                    cout<<s->data<<endl;
                }
				//	cout<<"found here !!"<<endl;
                }
            }
				file.close();
				s=s->next;
        }
		//	cout<<endl;
    }


	}
	if(found==0)
		{
			cout<<"\npossible anagrams not found!!\n";
		}
}


int main()
{

char *word=new char[10000];
clear_head();
cout<<"Enter a word : ";
cin>>word;
if(strlen(word)<8)
{

generate(word,0,strlen(word)-1);
cout<<"the possible anagrams for the word are :\n"<<endl;
traversal(word);
}
else
cout<<"the word is large.!"<<endl;

return 0;
}
