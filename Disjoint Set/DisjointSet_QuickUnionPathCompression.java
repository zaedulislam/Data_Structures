/***
 * Quick Union by Path Compression Optimization implementation of a Disjoint Set
 */
class DisjointSet_QuickUnionPathCompression {
    private int[] parent;
    private int[] rank;

    public DisjointSet_QuickUnionPathCompression(int size) {
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int find(int u) {
        if (u == parent[u]) {
            return u;
        }

        return parent[u] = find(parent[u]);
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
        DisjointSet_QuickUnionPathCompression uf = new DisjointSet_QuickUnionPathCompression(10);
        // 1-2-5-6-7 3-8-9 4
        uf.union(1, 2);
        uf.union(2, 5);
        uf.union(5, 6);
        uf.union(6, 7);
        uf.union(3, 8);
        uf.union(8, 9);
        System.out.println(uf.connected(1, 5)); // true
        System.out.println(uf.connected(5, 7)); // true
        System.out.println(uf.connected(4, 9)); // false
        // 1-2-5-6-7 3-8-9-4
        uf.union(9, 4);
        System.out.println(uf.connected(4, 9)); // true
    }
}
