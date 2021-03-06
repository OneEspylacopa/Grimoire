struct Node {
	Node *child[2]; int key; int size, count, aux;
	inline Node(int _aux) {
		child[0] = child[1] = 0; key = size = count = 0; aux = _aux;
	}
	inline void update() { size = count + child[0]->size + child[1]->size; }
};
Node *null;
inline void print(Node *&x) {
	if (x == null) return; print(x->child[0]); printf("%d ", x->key);
	print(x->child[1]);
}
inline Node* create(int key)
	Node *x = new Node(rand() % INT_MAX); x->key = key; x->count = x->size = 1;
	x->child[0] = x->child[1] = null; return x;
}
inline void rotate(Node *&x, int dir) {
	Node *y = x->child[!dir]; x->child[!dir] = y->child[dir]; y->child[dir] = x;
	x->update(); y->update(); x = y;
}
inline void insert(Node *&x, int key) {
	if (x == null) { x = create(key); return; }
	if (x->key == key) x->count++;
	else if (x->key > key) {
		insert(x->child[0], key); if (x->child[0]->aux < x->aux) rotate(x, 1);
	} else {
		insert(x->child[1], key); if (x->child[1]->aux < x->aux) rotate(x, 0);
	} x->update();
}
inline void erase(Node *&x, int key) {
	if (x == null) return;
	if (x->key == key) {
		if (x->count > 1) x->count--;
		else if (x->child[0] == null && x->child[1] == null) {
			delete(x); x = null; return;
		} else if (x->child[0]->aux < x->child[1]->aux)
			rotate(x, 1), erase(x->child[1], key);
		else rotate(x, 0), erase(x->child[0], key);
	} else if (x->key > key) erase(x->child[0], key);
	else erase(x->child[1], key);
	x->update();
}
inline void prepare() { null = new Node(INT_MAX); }