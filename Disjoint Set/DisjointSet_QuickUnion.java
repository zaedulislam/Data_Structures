/***
 * Quick Union implementation of a Disjoint Set
 */
class DisjointSet_QuickUnion {
    private int[] parent;

    public DisjointSet_QuickUnion(int size) {
        parent = new int[size];

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    public int find(int u) {
        while (u != parent[u]) {
            u = parent[u];
        }

        return u;
    }

    public void union(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU != parentV) {
            parent[parentV] = parentU;
        }
    }

    public boolean connected(int u, int v) {
        return find(u) == find(v);
    }

    public static void main(String[] args) {
        DisjointSet_QuickUnion uf = new DisjointSet_QuickUnion(10);
        // 1-2-5-6-7 3-8-9 4
        uf.union(1, 2);
        uf.union(2, 5);
        uf.union(5, 6);
        uf.union(6, 7);
        uf.union(3, 8);
        uf.union(8, 9);

        uf.union(1, 8);

        System.out.println(uf.connected(1, 9)); // true
    }
}
