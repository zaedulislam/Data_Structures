/***
 * Quick Union by Rank implementation of a Disjoint Set
 */
class DisjointSet_QuickUnionByRank {
    private int[] parent;
    private int[] rank;

    public DisjointSet_QuickUnionByRank(int size) {
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 1;
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
            if (rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            } else if (rank[parentU] < rank[parentV]) {
                parent[parentU] = parentV;
            } else {
                parent[parentV] = parentU;
                rank[parentU] += 1;
            }
        }
    }

    public boolean connected(int u, int v) {
        return find(u) == find(v);
    }

    public static void main(String[] args) {
        DisjointSet_QuickUnionByRank uf = new DisjointSet_QuickUnionByRank(10);
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
