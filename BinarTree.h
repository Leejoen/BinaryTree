#include <iostream>

#pragma once

template<typename T> class BinaryTree {
	template <typename T> class BinaryTreeItem {
	public:
		BinaryTreeItem<T>() :item() {}
		~BinaryTreeItem<T>() {}

		T getItem() { return item; }
		void setItem(T itm) { item = itm; }

		BinaryTreeItem<T>* getLeft() { return left; }
		void setLeft(BinaryTreeItem<T>* lft) { left = lft; }

		BinaryTreeItem<T>* getRight() { return right; }
		void setRight(BinaryTreeItem<T>* rgt) { right = rgt; }

		BinaryTreeItem<T>* getParent() { return parent; }
		void setParent(BinaryTreeItem<T>* prnt) { parent = prnt; }

	private:
		T item;
		BinaryTreeItem<T>* left = nullptr;
		BinaryTreeItem<T>* right = nullptr;
		BinaryTreeItem<T>* parent = nullptr;
	};

public:
	BinaryTree<T>() {}
	~BinaryTree<T>() {}

	bool addItem(T itm, T loc) {
		if (root == nullptr) {
			root = new BinaryTreeItem<T>();
			root->setItem(itm);
			return true;
		}

		if (findItem(itm) != nullptr) return false;

		BinaryTreeItem<T>* insertLoc = findItem(loc);
		if (insertLoc == nullptr) return false;

		if (insertLoc->getLeft() == nullptr) {
			BinaryTreeItem<T>* newItem = new BinaryTreeItem<T>();
			newItem->setItem(itm);
			newItem->setParent(insertLoc);
			insertLoc->setLeft(newItem);
			return true;
		}

		if (insertLoc->getRight() == nullptr) {
			BinaryTreeItem<T>* newItem = new BinaryTreeItem<T>();
			newItem->setItem(itm);
			newItem->setParent(insertLoc);
			insertLoc->setRight(newItem);
			return true;
		}

		return false;
	}

	bool remove(T itm) {
		BinaryTreeItem<T>* removeItem = findItemRecursionStart(itm);
		if (removeItem == nullptr || removeItem->getLeft() != nullptr || removeItem->getRight() != nullptr) return false;

		if (removeItem == root) root = nullptr;

		if (removeItem->getParent()->getLeft() == removeItem) {
			removeItem->getParent()->setLeft(nullptr);
		} else {
			removeItem->getParent()->setRight(nullptr);
		}

		delete removeItem;
	}

	void show() {
		if (root == nullptr) return;
		showTree(root, "");
	}

private:
	BinaryTreeItem<T>* root = nullptr;

	BinaryTreeItem<T>* findItem(T itm) {
		if (root == nullptr) return nullptr;

		BinaryTreeItem<T>* cur = root;
		int state = 0;

		while (true) {
			if (cur->getItem() == itm) return cur;
			if (state < 1 && cur->getLeft() != nullptr) { cur = cur->getLeft(); state = 0; }
			else if (state < 2 && cur->getRight() != nullptr) {
				cur = cur->getRight();  state = 0;
			} else {
				if (cur->getParent() == nullptr) return nullptr;
				state = cur == cur->getParent()->getLeft() ? 1 : 2;
				cur = cur->getParent();
			}
		}
	}

	BinaryTreeItem<T>* findItemRecursion(BinaryTreeItem<T>* currItem, T itm) {
		if (currItem == nullptr) return nullptr;

		if (currItem->getItem() == itm) return currItem;

		BinaryTreeItem<T>* cur = findItemRecursion(currItem->getLeft(), itm);
		return (cur == nullptr) ? findItemRecursion(currItem->getRight(), itm) : cur;
	}

	BinaryTreeItem<T>* findItemRecursionStart(T itm) {
		return root == nullptr ? nullptr : findItemRecursion(root, itm);
	}

	void showTree(BinaryTreeItem<T>* currItem, std::string indent) {
		if (currItem == nullptr) return;

		std::cout << indent << currItem->getItem() << std::endl;

		showTree(currItem->getLeft(), indent + "  ");
		showTree(currItem->getRight(), indent + "  ");
	}
};
