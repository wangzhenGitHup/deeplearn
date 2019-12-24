#pragma once

template<class K, class V>
class RBTree
{
public:
	RBTree();
	~RBTree();
	int GetSize();
	bool IsEmpty();
	void Add(K key, V value);

private:
	enum NodeColor
	{
		RED = 0,
		BLACK = 1,
	};

	struct TreeNode
	{
		TreeNode(K key, V value)
		{
			_key = key;
			_value = value;
			_leftChild = _rightChild = nullptr;
			_color = RED;
		}

		K _key;
		V _value;
		TreeNode* _leftChild;
		TreeNode* _rightChild;
		NodeColor _color;
	};

	TreeNode* addChild(TreeNode* pRoot, K key, V value)
	{
		if (pRoot == nullptr)
		{
			TreeNode* pNewNode = new TreeNode(key, value);
			_size++;
			return pNewNode;
		}

		if (key < pRoot->_key)
		{
			pRoot->_leftChild = addChild(pRoot->_leftChild, key, value);
		}
		else if (key > pRoot->_key)
		{
			pRoot->_rightChild = addChild(pRoot->_rightChild, key, value);
		}

		return pRoot;
	}

	NodeColor isRed(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
		{
			return BLACK;
		}

		return pRoot->_color;
	}
private:
	TreeNode* _root = nullptr;
	int _size;
};

template<class K, class V>
RBTree<K, V>::RBTree()
{
	_size = 0;
}

template<class K, class V>
RBTree<K, V>::~RBTree()
{
}

template<class K, class V>
inline int RBTree<K, V>::GetSize()
{
	return _size;
}

template<class K, class V>
inline bool RBTree<K, V>::IsEmpty()
{
	return _size == 0;
}

template<class K, class V>
void RBTree<K, V>::Add(K key, V value)
{
	_root = addChild(_root, key, value);
}
