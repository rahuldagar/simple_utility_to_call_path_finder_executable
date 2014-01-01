#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include <iomanip.h>
#include <iostream.h>
#include<string.h>

struct map4
{  int id;
   int distance2;
   int type;
   struct map4* next1;
}*head_map4=NULL,*temp_map4,*temp2_map4;
struct map3
{  int id;
   float time1;
   int tp;
   int dp;
   float distance1;
   struct map4* next2;
   struct map3* next1;
}*head_map3=NULL,*temp_map3,*temp2_map3;

struct map2
{  char name[80];
   int id;
   int link[10];
   int dis3[10];
   int xp;
   int yp;
   int type[10];
}head_map2,*head2_map2;
struct link
{  int id;
   int dis;
   int type;
   struct link *next;
}*temp_link,*temp2_link,*head_link;
struct map
{  int id;
   int xp;
   int yp;
   char name[80];
   struct map *next;
   struct link *next2;
}*temp_map,*temp2_map,*head_map;
struct stack
{   int id;
	int check;
	int d;
	int type;
	struct stack *next;
	struct stack *pre;
}*temp_stack,*temp2_stack,*head_stack;
void pstack();
void mapfile();
int path(int ch1,int ch2,struct map *pointer);
struct map* rollback();
void put_stack(int id1,int dis1,int type1);
int check(int id1,int ch1,int ch2);
void check1()
{ temp_map3=head_map3;
  while(temp_map3!=NULL)
  {  temp_map4=temp_map3->next2;
  //   while(temp_map4!=NULL)
 //   { // printf("\nid %d\ndis %d\ntype %d\n",temp_map4->id,temp_map4->distance2,temp_map4->type);
 //      temp_map4=temp_map4->next1;
  //  }
    printf("\ndp- %d tp- %d",temp_map3->dp,temp_map3->tp);
 //   getch();

    temp_map3=temp_map3->next1;
  }
}
void pixelmove()
{ float i=0,vx=0,d4,vy=0,time4=0,j=0,k=0,time2,type1,l=0,d3=0,px1,py1,px2,py2;
  int ch;
  clock_t start, end;

  start = clock();
  temp_map3=head_map3;
  while(temp_map3->dp!=1)
  { temp_map3=temp_map3->next1;
  }
  temp_map=head_map;
  while(temp_map->id != temp_map3->id)
  {   temp_map=temp_map->next;
  }
  px1=temp_map->xp;
  py1=temp_map->yp;
  temp_map4=temp_map3->next2;
  while(temp_map4!=NULL)
  { 	temp2_map=head_map;
	while(temp2_map->id != temp_map4->id)
	{   temp2_map=temp2_map->next;
	}
	px2=temp2_map->xp;
	py2=temp2_map->yp;
	type1=temp_map4->type;
//	d3=(px2-px1)*(px1-px2);
//	d3+=(py2-py1)*(py2-py1);
//	d3=sqrt(d3);
	d4=temp_map4->distance2;

       //	if(type1==1)
       //	{
	time2=d4/2;
	 //  vx=80*((px2-px1)/d3);
	 //  vy=80*((py2-py1)/d3);
	 //  for(i=0;i<10;i++)
	 //  {  // circle()
	   time4=0;
	   time2=time2*60*60*100;
	   vx=(px2-px1)/time2;
	   vy=(py2-py1)/time2;
	   setcolor(8);
	   i=0;
	   while( ch!=px2 && ch!=px2+1  && ch!=px2-1)
	 {//  delay(2000);
	   time4=time4+30;
	   circle(px1+ (vx)*time4*i , py1+ (vy)*time4*i,10 );
	   i++;
	//   if((px1+ (vx)*time4*i)==px2 && (py1+ (vy)*time4*i) ==py2)
	//   break;
	   ch= px1+ (vx)*time4*i;
	   getch();
	 }



//delay(2000);

//end = clock();
//printf("The time was: %f\n", (end - start) / CLK_TCK);
       px1=px2;
       py1=py2;
       temp_map4=temp_map4->next1;

      }












  }



void drawgraph()
{  int x1,y1,x2,y2,i,j,k;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   temp_map=head_map;
   while(temp_map!=NULL )
   {   //	  k=0;
       //	  j=0;
       //	  temp_map=head_map;
       //	  while(temp_map->id!=temp_map3->id)
      //	  {    temp_map=temp_map->next;
      //	  }
	  x1=temp_map->xp;
	  y1=temp_map->yp;
	 // temp2_map=temp2_map->next;
	 // n=temp->salary;
	    temp2_map=head_map;
	  while(temp2_map!=NULL)
	  {
	      //	while(temp_map->id!=temp_map4->id)
	      //	{    temp_map=temp_map->next;
	      //	}
		x2=temp2_map->xp;
		y2=temp2_map->yp;
		if(y2>y1)
		{
		for(i=x1-10;i<x1+10;i++)
		{    j=y2+x1-i;
		     setcolor(getmaxcolor());
		     line(i,y1,x2,j);
		}
		}

		if(y2<y1)
		{
		for(i=x1+10;i>x1-10;i--)
		{    j=y2+x1-i;
		     setcolor(getmaxcolor());
		     line(i,y1,x2,j);
		}
		}
		if(y2==y1)
		{
		  for(i=0;i<10;i++)
		  {  line(x1,y1+i,x2,y2+i);
		  }

		}
		if(x1==x2)
		{ for(i=0;i>10;i++)
		  {  line(x1+i,y1,x2+1,y2);
		  }
		}
	    /*	for(i=y1-10;i<y1+10;i++)
		{    j=y2+y1-i;
		     setcolor(getmaxcolor());
		     line(x1,i,x2,j);
		}  */

	       //	line(x1,y1,x2,y2);
	  //	getch();
		temp2_map=temp2_map->next;
	  }
       //	  temp_map3->dp=k+1;
       //	  temp_map3->tp=j+1;
	  temp_map=temp_map->next;

	//  getch();
  }

 temp_map=head_map;
 setcolor(9);
 while(temp_map!=NULL)
 { for(i=0;i<20;i++)
   {     rectangle(temp_map->xp-i,temp_map->yp-i,temp_map->xp+i,temp_map->yp+i);
   }
   temp_map=temp_map->next;
 }
  getch();
  pixelmove();

  closegraph();

}
void sort1()
{ int k=0,j=0;
  temp_map3=head_map3;
   while(temp_map3!=NULL )
   {  	  k=0;
	  j=0;
	  temp2_map3=head_map3;
	 // n=temp->salary;
	  while(temp2_map3!=NULL)
	  {  if(temp2_map3->distance1 > temp_map3->distance1)
		{ k++;

		}

	     if(temp2_map3->time1 > temp_map3->time1)
		{ j++;

		}
		temp2_map3=temp2_map3->next1;
	  }
	  temp_map3->dp=k+1;
	  temp_map3->tp=j+1;
	  temp_map3=temp_map3->next1;
  }
 check1();

}

void traffic()
{  float i=0,k=0,z=0,l=0;
   printf("\nenter traffic conditions");
   scanf("%d",&k);
   temp_map3=head_map3;
  while(temp_map3!=NULL)
  {  temp_map4=temp_map3->next2;
     i=0;
   //  k=0;
     l=0;
     z=0;
     while(temp_map4!=NULL)
    { // printf("\nid %d\ndis %d\ntype %d\n",temp_map4->id,temp_map4->distance2,temp_map4->type);

       if(k==1)
       {    if(temp_map4->type == 1)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/80;
	    }
	    if(temp_map4->type == 2)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/60;
	    }
	    if(temp_map4->type == 3)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/40;
	    }
	    if(temp_map4->type == 4)
	    {  i+=temp_map4->distance2;
	       z+=(temp_map4->distance2);
	       z=z/30;
	    }

	   l+=10;
       }
       if(k==3)
       {    if(temp_map4->type == 1)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/64;
	    }

	    if(temp_map4->type == 2)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/48;
	    }
	    if(temp_map4->type == 3)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/32;
	    }
	    if(temp_map4->type == 4)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/24;
	    }
	    l+=30;
       }
       if(k==2)
       {    if(temp_map4->type == 1)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/72;
	    }
	    if(temp_map4->type == 2)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/54;
	    }
	    if(temp_map4->type == 3)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/36;
	    }
	    if(temp_map4->type == 4)
	    {  i+=temp_map4->distance2;
	       z=(temp_map4->distance2);
	       z=z/27;
	    }

	  l+=20;
       }
       temp_map4=temp_map4->next1;
    }
    z=z+l;
    temp_map3->time1=z;
    temp_map3->distance1=i;
//    getch();
    temp_map3=temp_map3->next1;
  }
  sort1();
}

void main( int argc, char* argv[])
{  int i=0,j=0,k=0,ch1,ch2,ch3,z;
   FILE *fu;
   //printf("\n\t\t\t1.Predefined Map\n\t\t\t2.User Input Map\n\t\t\t");
   //scanf("%d",&ch3);
   for (int n = 1; n < argc; n++)
   { cout << setw( 2 ) << n << ": " << argv[ n ] << '\n';
    z=atoi(argv[n]);
    //cout<<z<<"\n";
   if(n==1)
   ch1=z;
   else
   ch2=z;
   }

   ch3=1;
   if(ch3==2)
   {  fu=fopen("c:\\project\\new.dat","wb");
//   printf("\nenter no of nodes  ");
//   scanf("%d",&ch1);

   head_map=NULL;
   for(i=0;i<ch1;i++)
   {  temp2_map=(struct map *)malloc(sizeof(struct map));
	  printf("\nenter id  ");
	  scanf("%d",&temp2_map->id);
	  head_map2.id=temp2_map->id;
	  printf("\nenter no of links");
	  scanf("%d",&ch2);
	  printf("\nenter name of place");
	  flushall();
	  gets(head_map2.name);
	  flushall();
	  printf("\nenter x coordinate  ");
	  scanf("%d",&temp2_map->xp);
	  head_map2.xp=temp2_map->xp;
	  printf("\nenter y coordinate  ");
	  scanf("%d",&temp2_map->yp);
	  head_map2.yp=temp2_map->yp;
	  strcpy(temp2_map->name,head_map2.name);
	  for(z=0;z<10;z++)
	  {  head_map2.link[z]=-1;
		 head_map2.dis3[z]=-1;
		 head_map2.type[z]=-1;
	  }
	  head_link=NULL;
	  temp2_map->next=NULL;
	  temp2_map->next2=NULL;
	  for(j=0;j<ch2;j++)
	  {     temp2_link=(struct link *)malloc(sizeof(struct link));
		printf("\nenter link id  ");
		scanf("%d",&temp2_link->id);

		printf("\nenter distance");
		scanf("%d",&temp2_link->dis);
		printf("\nenter type");
		scanf("%d",&temp2_link->type);
		head_map2.link[j]=temp2_link->id;
		head_map2.dis3[j]=temp2_link->dis;
		head_map2.type[j]=temp2_link->type;
		if(head_link==NULL)
		{ head_link=temp_link=temp2_link;
		 temp2_map->next2=temp2_link;
		}
		else
		{ temp_link->next=temp2_link;
		  temp_link=temp2_link;
		}
		temp2_link->next=NULL;
	  }
	 if(head_map==NULL)
	 {   head_map=temp_map=temp2_map;
	 }
	 else
	 {   temp_map->next=temp2_map;
		 temp_map=temp2_map;
	 }

	   fwrite(&head_map2,sizeof(struct map2),1,fu);
	}
   fclose(fu);
  }
  else
  {  mapfile();
  }
  head_stack=NULL;
//  printf("\nenter places between which path is to be found");
//  scanf("%d%d",&ch1,&ch2);
//  ch1=(int)argv[0];
//  ch2=(int)argv[1];
  temp2_stack=(struct stack *)malloc(sizeof(struct stack));
  temp2_stack->next=NULL;
  temp2_stack->pre=NULL;
  temp2_stack->id=ch1;
  temp2_stack->check=0;
  temp2_stack->d=0;
  head_stack=temp2_stack;
  temp_stack=head_stack;
  temp_map=head_map;
  while(temp_map->id!=ch1)
  {  temp_map=temp_map->next;
  }
  i=path(ch1,ch2,temp_map);
//  check1();
//  traffic();
// drawgraph();


}

int path(int ch1,int ch2,struct map *pointer)
{   int flag=0;
	if(pointer->id==ch2)
	{  while(pointer->id==ch2 && pointer!=NULL)
	   { //printf("\npath found");
		 pstack();
	    //	 getch();
		 pointer=rollback();
	   }
	}
	if(pointer==NULL)
	{  //printf("\nall path found");
	  // getch();
	   return 1;
	}
	temp_link=pointer->next2;
	while(temp_link!=NULL)
	{ flag=check(temp_link->id,ch1,ch2);
	  if(flag==0)
	  {  put_stack(temp_link->id,temp_link->dis,temp_link->type);
	  }
	  temp_link=temp_link->next;
	}
	  pointer=rollback();
	  path(ch1,ch2,pointer);
}
struct map * rollback()
{    temp2_stack=temp_stack;
	 while(temp2_stack->check!=1 && temp2_stack!=NULL)
	 {  temp2_stack=temp2_stack->pre;
	 }
	 if(temp2_stack==NULL)
	 { return NULL;
	 }
	 temp2_stack->check=0;
	 temp_stack=temp2_stack;
	 temp_stack->next=NULL;
	 temp_map=head_map;
	 while(temp_map->id!=temp2_stack->id && temp_map!=NULL)
	 {  temp_map=temp_map->next;
	 }
	 return temp_map;
}
int check(int id1,int ch1,int ch2)
{   if(id1==ch1)
	{  return 1;
	}
	temp2_stack=head_stack;
	while(temp2_stack!=NULL)
	{     if(temp2_stack->id==id1 && temp2_stack->check==0)
		  {return 1;
		  }
	   temp2_stack=temp2_stack->next;
	}
   return 0;
}
void put_stack(int id1, int dis1,int type1)
{ temp2_stack=(struct stack *)malloc(sizeof(struct stack));
  temp2_stack->next=NULL;
  temp2_stack->pre=temp_stack;
  temp_stack->next=temp2_stack;
  temp2_stack->id=id1;
  temp2_stack->check=1;
  temp2_stack->type=type1;
  temp2_stack->d=dis1;
  temp_stack=temp2_stack;
}
void pstack()
{  int dist=0,k=0;
 FILE *p;
 p=fopen("d:\\pathf.txt","a");
   temp2_stack=head_stack;
   printf("\npath found\n");
   while(temp2_stack!=NULL)
   {   if(temp2_stack->check==0)
	   {  printf("-%d--%d",temp2_stack->id,temp2_stack->d);
		  fprintf(p,"%d %d ",temp2_stack->id,temp2_stack->d);
		  dist+=temp2_stack->d;
		  if(k==0)
		  { temp2_map3=(struct map3*)malloc(sizeof(struct map3));
			temp2_map3->id=temp2_stack->id;
	   //		temp2_map3->type=temp2_stack->type;
	   //		temp2_map3->distance2=temp2_stack->d;
			temp2_map3->next2=NULL;
			temp2_map3->next1=NULL;
			if(head_map3==NULL)
			{  head_map3=temp_map3=temp2_map3;
			}
			else
			{  temp_map3->next1=temp2_map3;
			   temp_map3=temp2_map3;
			}

		  }
		  else
		  {	temp2_map4=(struct map4*)malloc(sizeof(struct map4));
			temp2_map4->id=temp2_stack->id;
			temp2_map4->type=temp2_stack->type;
			temp2_map4->distance2=temp2_stack->d;
	   //		temp2_map4->next2=NULL;
			temp2_map4->next1=NULL;
			if(temp2_map3->next2==NULL)
			{ temp2_map3->next2=temp2_map4;
			  temp_map4=temp2_map4;
			}
			else
			{  temp_map4->next1=temp2_map4;
			   temp_map4=temp2_map4;
			}
		  }

	   }
	   temp2_stack=temp2_stack->next;
	   k++;
 }
  printf("   total distance-  %d",dist);
  fprintf(p,"%d\n",dist);
  fclose(p);
}


void mapfile()
{   FILE *fp;
    int i=0,j=0,ch2;
    fp=fopen("d:\\pathf.txt","wt");
    fclose(fp);
    fp=fopen("d:\\new.dat","rb");
    while( (fread(&head_map2,sizeof(struct map2),1,fp)) !=NULL)
   {  temp2_map=(struct map *)malloc(sizeof(struct map));
	 // printf("\nenter id  ");
	  temp2_map->id=head_map2.id;
	 // printf("\nenter no of links");
	  strcpy(temp2_map->name,head_map2.name);
	  temp2_map->xp=head_map2.xp;
	  temp2_map->yp=head_map2.yp;
	  ch2=0;
	  while(head_map2.link[ch2]!=-1)
	  {  ch2++;
	  }
	  head_link=NULL;
	  temp2_map->next=NULL;
	  temp2_map->next2=NULL;
	  for(j=0;j<ch2;j++)
	  {     temp2_link=(struct link *)malloc(sizeof(struct link));
	      //	printf("\nenter link id  ");
		temp2_link->id=head_map2.link[j];
	      //	printf("\nenter distance");
		temp2_link->dis=head_map2.dis3[j];
		temp2_link->type=head_map2.type[j];
		if(head_link==NULL)
		{ head_link=temp_link=temp2_link;
		 temp2_map->next2=temp2_link;
		}
		else
		{ temp_link->next=temp2_link;
		  temp_link=temp2_link;
		}
		temp2_link->next=NULL;
	  }
	 if(head_map==NULL)
	 {   head_map=temp_map=temp2_map;
	 }
	 else
	 {   temp_map->next=temp2_map;
	     temp_map=temp2_map;
	 }

	}
	fclose(fp);
 }