#include "QuadTree.h"
#include <cmath>

QuadTree::QuadTree() :
	topLeft{ treePoint() },
	bottomRight{ treePoint() },
	node{ nullptr },
	nw{ nullptr },
	ne{ nullptr },
	sw{ nullptr },
	se{ nullptr }
{
}

QuadTree::QuadTree(treePoint topleft, treePoint bottomright) : QuadTree()
{
	this->topLeft = topleft;
	this->bottomRight = bottomright;
}

void QuadTree::Insert(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	// ���� ������ �ƴϸ� ����
	if (!IsInBound(node->position))
	{
		return;
	}

	// ���� ������ ���� ���� ( 1 x 1 )�̶�� �� �̻� ���� �Ұ���
	if (std::abs(topLeft.x - bottomRight.x) <= 1 &&
		std::abs(topLeft.y - bottomRight.y) <= 1)
	{
		if (this->node == nullptr)
		{
			this->node = node;
		}
		return;
	}

	// ����
	if ((topLeft.x + bottomRight.x) / 2 >= node->position.x)
	{
		if ((topLeft.y + bottomRight.y) / 2 >= node->position.y)
		{
			// �ϼ�
			if (nw == nullptr)
			{
				nw = std::make_unique<QuadTree>(
					treePoint(topLeft.x, topLeft.y),
					treePoint((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2)
				);
			}
			nw->Insert(node);
		}
		else
		{
			// ����
			if (sw == nullptr)
			{
				sw = std::make_unique<QuadTree>(
					treePoint(topLeft.x, (topLeft.y + bottomRight.y) / 2),
					treePoint((topLeft.x + bottomRight.x) / 2, bottomRight.y)
				);
			}
			sw->Insert(node);
		}
	}
	// ����
	else
	{
		if ((topLeft.y + bottomRight.y) / 2 >= node->position.y)
		{
			// �ϵ�
			if (ne == nullptr)
			{
				ne = std::make_unique<QuadTree>(
					treePoint((topLeft.x + bottomRight.x) / 2, topLeft.y),
					treePoint(bottomRight.x, (topLeft.y + bottomRight.y) / 2)
				);
			}
			ne->Insert(node);
		}
		else
		{
			// ����
			if (se == nullptr)
			{
				se = std::make_unique<QuadTree>(
					treePoint((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2),
					treePoint(bottomRight.x, bottomRight.y)
				);
			}
			se->Insert(node);
		}
	}
}

Node* QuadTree::Search(treePoint pt)
{
	// ���� ������ �ƴϸ� ����
	if (!IsInBound(pt))
	{
		return nullptr;
	}

	// node�� ���� ������ ���̻� ���� �Ұ����� ���� ����
	if (node != nullptr)
	{
		return node;
	}

	// ����
	if ((topLeft.x + bottomRight.x) / 2 >= pt.x)
	{
		// �ϼ�
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{
			if (nw == nullptr)
			{
				return nullptr;
			}
			return nw->Search(pt);
		}
		// ����
		else
		{
			if (sw == nullptr)
			{
				return nullptr;
			}
			return sw->Search(pt);
		}
	}
	// ����
	else
	{
		// �ϵ�
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{
			if (ne == nullptr)
			{
				return nullptr;
			}
			return ne->Search(pt);
		}
		// ����
		else
		{
			if (se == nullptr)
			{
				return nullptr;
			}
			return se->Search(pt);
		}
	}
}

bool QuadTree::IsInBound(treePoint pt)
{
	return (pt.x >= topLeft.x && pt.x <= bottomRight.x && pt.y >= topLeft.y && pt.y <= bottomRight.y);
}
