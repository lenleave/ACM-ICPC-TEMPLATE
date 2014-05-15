

#define MAXN 110
#define INF 0xFFFFFF
int n;
int maps[MAXN][MAXN];
int nearvex[MAXN];
//记录T’(还没被选中的点)内个顶点到T(已经选中的点)内哪个点最近
//当值为-1时表示已经被选中 
//注：如果题目中不要求路径，只要求距离，那么该数组可省略
//省略后用lowcost取代，-1表示选中，每次求出一个最近的点直接把权值加在sum上 
int lowcost[MAXN];
//存放T'(还没被选中的点)到T(已经选中的点)的权值最小的边 

int prim(int s)
{
	int sum=0;
	for(int i=1;i<=n;i++)  //初始化nearvex lowcast 
	{
		nearvex[i]=s;
		lowcost[i]=maps[s][i];
	}
	nearvex[s]=-1;
	//如果所给路径会怎么样？
	//中途有无法选出最近点的情况，就是i还未到n却出现tag=-1 
	for(int i=1;i<n;i++)   
	{
		int min=INF;
		int tag=-1;
		for(int j=1;j<=n;j++)
		{
			if(nearvex[j]!=-1 && lowcost[j]<min)
			{
				tag=j;
				min=lowcost[j];
			}
		}
		if(tag!=-1)
		{
			nearvex[tag]=-1;
			sum+=lowcost[tag];
			for(int j=1;j<=n;j++)
			{
				if(nearvex[j]!=-1 && lowcost[j]>maps[tag][j])
				{
					lowcost[j]=maps[tag][j];
					nearvex[j]=tag;
				}
			}
		}
	}
	return sum;
}
