#include <iostream>
#include <chrono>


class TreeNode
{
	public:
		TreeNode() : value(""), count(1), left(nullptr),
			right(nullptr) { }
		TreeNode(const std::string &s = std::string(), TreeNode *lchild = nullptr,TreeNode *right = nullptr) :
			value(s), count(1), left(lchild), right(rchild) { }
		TreeNode(const TreeNode &tn) :
			value(tn -> value), count(1), left(tn -> left), right(tn -> right)
		{
			if (left)
				left -> CopyTree();
			if (right)
				right -> CopyTree();
		}
		~TreeNode()
		{
			if (!root -> ReleaseTree())
				delete root;
		}

	private:
		std::string value;
		int count;
		TreeNode *left;
		TreeNode *right;

		void CopyTree()
		{
			if (left)
				left -> CopyTree();  // 左子树不空,拷贝左子树
			if(right)
				right -> CopyTree(); // 右子树不空,拷贝右子树
			count++;
		}

		int ReleaseTree()
		{
			if (left)
			{
				if (!left -> CopyTree())
					delete left;
			}
			if (right)
			{
				if (!right -> CopyTree())
					delete right;
			}
			count--;
			return count;
		}
};


class BinStrTree
{
	public:
		BinStrTree() : root(nullptr) { }
		BinStrTree(TreeNode *t = nullptr) : root(t) { }
		BinStrTree(const BinStrTree &bst) :
			root(bst)
		{
			root -> CopyTree();   // 拷贝整棵树 
		}
		~BinStrTree()
		{
			// count 为0表示资源已被释放,是delete触发的析构函数,什么也不做即可
			if (count)
				ReleaseTree();
		}
	private:
		TreeNode *root;
};





int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
