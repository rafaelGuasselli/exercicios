#include<bits/stdc++.h>

using namespace std;

struct Node{
	int indMaior, indMenor;
	int left, right;
	int index;
};

Node* seg[100005];
int maior[100005];
int menor[100005];

void build(int index, int left, int right) {
	seg[index] = new Node();
	seg[index]->left = left;
	seg[index]->right = right;
	seg[index]->index = index;

	if (left == right) {
		seg[index]->indMaior = left;
		seg[index]->indMenor = left;
	} else {
		int mid = (left+right)/2;
		build(index*2+1, left, mid);
		build(index*2+2, mid+1, right);
		
		int indMaiorLeft = seg[index*2+1]->indMaior;
		int indMenorLeft = seg[index*2+1]->indMenor;
		int indMaiorRight = seg[index*2+2]->indMaior;
		int indMenorRight = seg[index*2+2]->indMenor;
		
		seg[index]->indMaior = maior[indMaiorLeft] > maior[indMaiorRight] ? indMaiorLeft : indMaiorRight;
		seg[index]->indMenor = menor[indMenorLeft] < menor[indMenorRight] ? indMenorLeft : indMenorRight;
	}
}

void update(int index, int value){
	Node* atual = seg[0];
	while (atual->right != atual->left) {
		atual->indMaior = value > maior[atual->indMaior] ? index : atual->indMaior;
		atual->indMenor = value < menor[atual->indMenor] ? index : atual->indMenor;

		int mid = (atual->left+atual->right)/2;
		atual = index > mid ? seg[atual->index*2+2] : seg[atual->index*2+1];
	}

	maior[index] = value > maior[index] ? value : maior[index];
	menor[index] = value < menor[index] ? value : menor[index];
}

pair<int, int> read(int index, int left, int right){
	Node* atual = seg[index];
	if (left == right) {
		return {atual->indMaior, atual->indMenor};
	}

	if (atual->indMaior != atual->indMenor && atual->left == left && atual->right == right) {
		return {atual->indMaior, atual->indMenor};
	}

	int mid = (atual->left+atual->right)/2;
	pair<int, int> leftValue = read(index*2+1, left, min(mid, right));
	pair<int, int> rightValue = read(index*2+2, max(mid+1, left), right);

	int indMenor = menor[leftValue.second] < menor[rightValue.second] ? leftValue.second : rightValue.second;
	int indMaior = maior[leftValue.first] > maior[rightValue.first] ? leftValue.first : rightValue.first;

	return {indMaior, indMenor};
}


int main() {

	return 0;
}