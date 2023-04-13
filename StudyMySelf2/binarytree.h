#pragma once
#include <iostream>

#include <queue>
#include <stack>

namespace mytree
{
	struct Node
	{
		int mData;
		Node* mLeft;
		Node* mRight;
		Node(int data, Node* left, Node* right)
		{
			mData = data;
			mLeft = left;
			mRight = right;
		}
	};

	class Binarytree
	{
	private:
		Node* mpRoot{};

	public:
		Binarytree()
		{
			mpRoot = CreateNode(0);
		}
		Node* GetRoot()
		{
			return mpRoot;
		}
		Node* CreateNode(int data)
		{
			return new Node(data, nullptr, nullptr);
		}
		Node* InsertLeft(Node* parent, int data)
		{
			parent->mLeft = CreateNode(data);
			return parent->mLeft;
		}
		Node* InsertRight(Node* parent, int data)
		{
			parent->mRight = CreateNode(data);
			return parent->mRight;
		}

		void Visit(Node* node)
		{
			std::cout << node->mData << " -> ";
		}

		// queue
		void BreadthFirst()
		{
			std::queue<Node*> q;
			q.push(mpRoot);

			while (!q.empty())
			{
				auto node = q.front();
				Visit(node);
				q.pop();
				if (node->mLeft != nullptr)
				{
					q.push(node->mLeft);
				}
				if (node->mRight != nullptr)
				{
					q.push(node->mRight);
				}

			}
		}

		// stack
		void DepthFirst()
		{
			std::stack<Node*> stack;
			stack.push(mpRoot);

			while (!stack.empty())
			{
				auto node = stack.top();
				Visit(node);
				stack.pop();
				if (node->mRight != nullptr)
				{
					stack.push(node->mRight);
				}
				if (node->mLeft != nullptr)
				{
					stack.push(node->mLeft);
				}
			}
		}

		void DepthFirstRecursive(Node* pNode)
		{
			if (pNode == nullptr)
			{
				return;
			}

			Visit(pNode);
			DepthFirstRecursive(pNode->mLeft);
			DepthFirstRecursive(pNode->mRight);
		}

		void InOrder(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}

			InOrder(node->mLeft);
			Visit(node);
			InOrder(node->mRight);
		}

		void PreOrder(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}

			Visit(node);
			PreOrder(node->mLeft);
			PreOrder(node->mRight);
		}

		void PostOrder(Node* node)
		{
			if (node == nullptr);
			{
				return;
			}

			PostOrder(node->mLeft);
			PostOrder(node->mRight);
			Visit(node);
		}

		bool Search(Node* node, int value)
		{
			if (node == nullptr)
			{
				return false;
			}

			return (node->mData == value) ||
				Search(node->mLeft, value) ||
				Search(node->mRight, value);
		}

		int Sum(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			return Sum(node->mLeft) + node->mData + Sum(node->mRight);
		}

		Node* Insert(Node* node, int data)
		{
			if (node == nullptr)
			{
				return CreateNode(data);
			}

			if (data < node->mData)
			{
				node->mLeft = Insert(node->mLeft, data);
			}
			else if (data > node->mData)
			{
				node->mRight = Insert(node->mRight, data);
			}
			
			return node;
		}
	};
}


