/**
 * Description: Preorder and Postorder stamps (Finds the preorder and postorder stamps for vertices of tree. Useful for checking if vertex is in subtree) 
 * Usage: preprocess O(V) 
 * Source: https://github.com/dragonslayerx 
 */


vector<vector<int> > preorder;
vector<vector<int> > postorder;

int prestamp[MAX];
int poststamp[MAX];
bool isVisited[MAX];

int counter = 0;
void preprocess(int u, int depth)
{
    isVisited[u] = true;
    nodes[depth].push_back(u);
    prestamp[u] = counter++;
    for (int i = 0; i < T[u].size(); i++) {
        int v = T[u][i];
        if (!isVisited[v]) {
            preprocess(v, depth+1);
        }
    }
    poststamp[u] = counter++;
}