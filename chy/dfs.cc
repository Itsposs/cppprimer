


#include <iostream>


int a[10], book[10], n;
void dfs(int step)  // 
{
	int i = 0;
	if(step == n + 1)
	{
		for(i = 1; i <= n; ++i)
		{
			std::cout << a[i] <<  " ";
		}
		std::cout << std::endl;
		return; 
	}

	for(i = 1; i <= n; ++i)
	{
		if(book[i] == 0)
		{
			a[step] = i;
			book[i] = 1;

			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}


int main(int argc, char *argv[])
{
	std::cin >> n;  // 0 < n < 9
	dfs(1);

	return 0;
}
