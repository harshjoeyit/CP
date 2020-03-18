// print graph

for(int i = 1; i <= n; i++)
{
   cout << i << "-> ";
   for(auto v: G[i])
       cout << v << " ";
   cout << endl;
}