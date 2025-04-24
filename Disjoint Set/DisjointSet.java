/***
 * This implementation of the “disjoint set” is optimized with both “path compression” and “union by rank”.
 */
class DisjointSet {
    private int[] parent;
    private int[] rank;

    public DisjointSet(int size) {
        parent = new int[size];
        // Use a rank array to record the height of each vertex, i.e., the "rank" of each vertex.
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            parent[i] = i;
            // The initial "rank" of each vertex is 1, because each of them is
            // a standalone vertex with no connection to other vertices.
            rank[i] = 1;
        }
    }

    // The find function here is the same as that in the disjoint set with path compression.
    public int find(int u) {
        if (u == parent[u]) {
            return u;
        }

        // Some ranks may become obsolete so they are not updated
        return parent[u] = find(parent[u]);
    }

    // The union function with union by rank
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
        DisjointSet disjointSet = new DisjointSet(10);
        // 1-2-5-6-7 3-8-9 4
        disjointSet.union(1, 2);
        disjointSet.union(2, 5);
        disjointSet.union(5, 6);
        disjointSet.union(6, 7);
        disjointSet.union(3, 8);
        disjointSet.union(8, 9);
        System.out.println(uf.connected(1, 5)); // true
        System.out.println(uf.connected(5, 7)); // true
        System.out.println(uf.connected(4, 9)); // false
        // 1-2-5-6-7 3-8-9-4
        disjointSet.union(9, 4);
        System.out.println(uf.connected(4, 9)); // true
    }
}
