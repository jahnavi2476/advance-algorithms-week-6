#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class HuffmanNode {
public:
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char character, int frequency) {
        this->character = character;
        this->frequency = frequency;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Compare {
public:
    bool operator() (HuffmanNode* node1, HuffmanNode* node2) {
        return node1->frequency > node2->frequency;
    }
};

void printHuffmanCodes(HuffmanNode* root, string code) {
    if (root == nullptr) {
        return;
    }

    if (root->character != '$') {
        cout << code << " ";
    }

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

HuffmanNode* buildHuffmanTree(vector<char>& characters, vector<int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    for (int i = 0; i < characters.size(); i++) {
        minHeap.push(new HuffmanNode(characters[i], frequencies[i]));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

int main() {
    int numCharacters;
    cout << "Enter the number of characters: ";
    cin >> numCharacters;

    vector<char> characters(numCharacters);
    vector<int> frequencies(numCharacters);

    cout << "Enter the characters: ";
    for (int i = 0; i < numCharacters; i++) {
        cin >> characters[i];
    }

    cout << "Enter the corresponding frequencies: ";
    for (int i = 0; i < numCharacters; i++) {
        cin >> frequencies[i];
    }

    HuffmanNode* root = buildHuffmanTree(characters, frequencies);
    printHuffmanCodes(root, "");

    return 0;
}
