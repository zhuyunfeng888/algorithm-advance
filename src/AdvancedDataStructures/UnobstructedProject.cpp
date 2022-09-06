#include <cstdio>

using namespace std;

#define N 1010

int fa[N];

int Find(int x) {
  int father = fa[x];
  while (x != father) {
    x = fa[x];
    father = fa[x];
  }
  return father;
}

void Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a != b)
    fa[a] = b;
}

int main() {
  while (true) {
    int n, m, i, ans = 0, x, y;
    scanf("%d", &n);
    if (n == 0)
      break;
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
      fa[i] = i;
    for (i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      Union(x, y);
    }
    for (i = 1; i <= n; i++)
      if (i == fa[i])
        ans++;
    printf("%d\n", ans - 1);
  }
  return 0;
}
