#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int sudu[9][9];
int suduFlag[9][9];


//输出9*9矩阵的数据
int showSudo()
{
	for( int y = 0; y < 9; y++ )
	{
		for( int x = 0; x < 9; x++ )
		{
			printf("%d ", sudu[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

//输出9*9矩阵的数据
int showsuduFlag()
{
	for( int y = 0; y < 9; y++ )
	{
		for( int x = 0; x < 9; x++ )
		{
			printf("%d ", suduFlag[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}


//判断这里填充这个值是否正确
//0： OK    -1 ：NO
int isNumberOk(int x, int y)
{
	int temx,temy;
	int i,j;
 	if( suduFlag[x][y] == 1) 
 	{
 		return 0;
 	}

	for ( i = 0; i < 9; i++ )
	{
		if( (sudu[x][y] == sudu[i][y]) && (i != x) )
		{
			break;
		}
	} 
	
	if( i < 9 )
	{
		return -1;
	}

	for ( i = 0; i < 9; i++ )
	{
		if( (sudu[x][y] == sudu[x][i]) && (i != y) )
		{
			break;
		}
	} 
	
	if( i < 9 )
	{
		return -1;
	}

	temx = x/3*3;
	temy = y/3*3;

	for ( i = temx; i < temx+3; i++ )
	{
		for ( j = temy; j < temy+3; j++ )
		{
			if( sudu[x][y] == sudu[i][j] && (i != x) && (j != y))
			{
				break;
			}			
		}
	} 

	if( (i < temx+3) || (j < temy+3) )
	{
		return -1;
	}	

	return 0;
}



//设置对应位置为指定值
int setNumber( int x, int y, int val)
{
	sudu[x][y] = val;
	suduFlag[x][y] = 1;
}


//将x,y之后的矩阵位置清空为1
int clearNumber( int x, int y)
{

	for( int i = x; i < 9; i++ )
	{
		if( suduFlag[i][y] != 1 )
		{
			sudu[i][y] = 0;
		}
	}

	for( int j = y+1; j < 9; j++ )
	{
		for( int i = 0; i < 9; i++ )
		{
			if( suduFlag[i][j] != 1 )
			{
				sudu[i][j] = 0;
			}
		}
	}
}



int calculatData(int x, int y)
{
	if( y >= 9 )
	{
		printf("y >= 9 \n");
		return 0;  //OK
	}


	for( int i = x; i < 9; i++ )
	{
		if( suduFlag[i][y] == 1 )
		{
			continue;
		}

		for(int v = 1; v <= 9; v++ )
		{
			sudu[i][y] = v;
			if ( isNumberOk(i,y) == 0)
			{
				if ( i+1 >= 9 )
				{
					if ( calculatData(0,y+1) == 0 )
					{
						return 0;
					}	
				}
				else
				{
					if ( calculatData(i+1,y) == 0 )
					{
						return 0;
					}		
				}
			}
		}
		sudu[i][y] = 0;
		return -1;

	}

	for( int j = y+1; j < 9; j++ )
	{
		for( int i = 0; i < 9; i++ )
		{
			if( suduFlag[i][j] == 1 )
			{
				continue;
			}

			for(int v = 1; v <= 9; v++ )
			{
				sudu[i][j] = v;
				if ( isNumberOk(i,j) == 0)
				{
					if ( i+1 >= 9 )
					{
						if ( calculatData(0,j+1) == 0 )
						{
							return 0;
						}	
					}
					else
					{
						if ( calculatData(i+1,j) == 0 )
						{
							return 0;
						}		
					}
					
				}
			}

			sudu[i][j] = 0;
			return -1;

		}
	}
	return 0;

}



int main()
{
	int x,y,val;
	memset(suduFlag, 0, sizeof(suduFlag));
	clearNumber(0,0);

	do
	{
		printf("请输入你要设置的位置和值(都为-1代表输入结束)： x y val ->\n");
		scanf("%d%d%d", &x, &y, &val);
		printf("you input is :x=%d y=%d val=%d\n", x, y, val);
		if( x == -1 && y == -1 && val == -1 )
		{
			printf("输入结束：：正在计算\n");
		}
		else if ( x == -1 || y == -1 || val == -1  )
		{
			printf("数据非法，从新输入\n");
		}
		else
		{
	 	   	sudu[x][y] = val;
	 	   	suduFlag[x][y] = 1;
		}
	}while( !((x == -1) && (y == -1) && (val == -1)) );

	// setNumber( 0, 0, 3);
	// setNumber( 0, 1, 7);
	// setNumber( 0, 4, 2);
	// setNumber( 0, 6, 6);
	// setNumber( 1, 1, 5);
	// setNumber( 1, 3, 8);
	// setNumber( 2, 0, 9);
	// setNumber( 2, 1, 6);
	// setNumber( 2, 8, 4);
	// setNumber( 3, 3, 9);
	// setNumber( 3, 5, 4);
	// setNumber( 3, 8, 3);
	// setNumber( 4, 4, 1);
	// setNumber( 5, 0, 4);
	// setNumber( 5, 3, 5);
	// setNumber( 5, 5, 8);
	// setNumber( 6, 0, 6);
	// setNumber( 6, 7, 7);
	// setNumber( 6, 8, 9);
	// setNumber( 7, 5, 1);
	// setNumber( 7, 7, 4);
	// setNumber( 8, 2, 5);
	// setNumber( 8, 4, 3);
	// setNumber( 8, 7, 6);
	// setNumber( 8, 8, 8);

	showSudo();

	int ret = calculatData(0,0);

	if( ret == 0 )
	{
		printf("Success calculat,  You Are Lucky Dog\n");
		showSudo();
	}
	else
	{
		printf("Failure calculat,  You Can To Death\n");
	}
	return 0;
}




