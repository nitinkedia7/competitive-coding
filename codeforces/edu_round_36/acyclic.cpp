#include <iostream>
using namespace std;

struct adj_node {
	int c;
	adj_node *ptr;
};

struct node {
	int c, parent, d, f, color;
	adj_node *link;
};

void push(adj_node **pHead, int c) {
	adj_node *temp = new adj_node;
	temp->c = c;
	temp->ptr = *pHead;
	*pHead = temp;
}

char pop(adj_node **pHead) {
	if (*pHead != NULL) {
		int c = (*pHead)->c;
		*pHead = (*pHead)->ptr;
		return c;
	}
}

void insert(adj_node **pHead, int c) {
	adj_node *temp = new adj_node;
	temp->c = c;
	temp->ptr = NULL;

	if (*pHead == NULL) {
		temp->ptr = NULL;
		*pHead = temp;
		return;
	}

	adj_node *next = *pHead;
	adj_node *prev = NULL;

	while (next != NULL) {
		if (next->c > c) break;
		prev = next;
		next = next->ptr;
	}
	if (next == NULL) {
		prev->ptr = temp;
	}
	else if (prev == NULL) {
		temp->ptr = *pHead;
		*pHead = temp;
		return;
	}
	else {
		temp->ptr = prev->ptr;
		prev->ptr = temp;
	}
}

void print(node *array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i].c << " "
			 << array[i].parent << " "
			 << array[i].d << " "
			 << array[i].f << " " << endl;

		adj_node *head = array[i].link;
		while (head != NULL) {
			cout << head->c << " ";
			head = head->ptr;
		}
		if (head == NULL) cout << "NULL" << endl;
	}
}

void dfs_enhanced(node *array, int n, int *flag) { // edge type
	for (int i = 0; i < n; i++) {
		array[i].c = i;
		array[i].parent = 0;
		array[i].d = -1;
		array[i].f = -1;
		array[i].color = -1;
	}
	// print(array, n);
	adj_node *stack = NULL;
	int time = 0;
	for (int i = 1; i <= n; i++) {
		if (array[i].color == -1) {
			array[i].color = 0;
			array[i].d = ++time;
			char y = i;
			push(&stack, y);

			while (stack != NULL) {
				int u = stack->c;

				adj_node *head = array[u].link;
				while (head != NULL) {
					int v = head->c;
					if (array[v].color == -1) {
						array[v].color = 0;
						array[v].parent = u;
						array[v].d = ++time;
						push(&stack, v);
						break;
					}
					else if (array[v].color == 0) {
              cout << u << "->" << v << endl;
	            (*flag)++;
					}
  			  head = head->ptr;
				}
				if (head == NULL) {
					int x = pop(&stack);
					array[x].color = 1;
					array[x].f = ++time;
				}
			}
		}
}
}
int main() {
  int n, e;
  cin >> n >> e;
  node array[n+1];
  for (int i = 1; i <= n; i++) {
    array[i].c = i;
    array[i].parent = 0;
    array[i].d = -1;
    array[i].f = -1;
    array[i].color = -1;
    array[i].link = NULL;
  }
  int c1, c2;
  for (int i = 0; i < e; i++) {
    cin >> c1 >> c2;
    insert(&(array[c1].link), c2);
  }
  int flag = 0;
  dfs_enhanced(array, n, &flag);
  cout << flag << endl;
  if (flag <= 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}
