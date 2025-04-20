/***
 * Quick Find implementation of a Disjoint Set
 */
class DisjointSet_QuickFind {
    private int[] root;

    public DisjointSet_QuickFind(int size) {
        root = new int[size];

        for (int i = 0; i < size; i++) {
            root[i] = i;
        }
    }

    public int find(int u) {
        return root[u];
    }

    public void union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            int size = root.length;

            for (int i = 0; i < size; i++) {
                if (root[i] == rootV) {
                    root[i] = rootU;
                }
            }
        }
    }

    public boolean connected(int u, int v) {
        return find(u) == find(v);
    }

    public static void main(String[] args) {
        DisjointSet_QuickFind uf = new DisjointSet_QuickFind(10);
        // 1-2-5-6-7 3-8-9 4
        uf.union(1, 2);
        uf.union(2, 5);
        uf.union(5, 6);
        uf.union(6, 7);
        uf.union(3, 8);
        uf.union(8, 9);

        uf.union(1, 3);

        System.out.println(uf.connected(1, 9)); // true
    }
}
