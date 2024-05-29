class Clustering:
    def __init__(self,output_file=None):
        self.matrix = None
        self.dimension = 0
        self.order = []
        self.parent = []
        self.groups = []
        self.output_file = output_file
    def initialize(self):
        for i in range(self.dimension):
            self.parent.append(i)
            members = {i}
            self.groups.append(members)

    def get(self, i):
        return self.parent[i]

    def union(self, a, b):
        a = self.get(a)
        b = self.get(b)
        for x in self.groups[a]:
            self.parent[x] = b
            self.groups[b].add(x)

    def read_matrix_from_file(self, file_path):
        with open(file_path, 'r') as file:
            header_row = file.readline().strip().split(',')
            self.dimension = len(header_row) - 1
            self.matrix = []

            for line in file:
                row = line.strip().split(',')
                self.matrix.append([float(row[i + 1]) for i in range(self.dimension)])
    
    def write_matrix_to_file(self, matrix,final):
        with open(self.output_file, 'w') as file:
            # Write header
            
            # header = [str(i) for i in range(len(matrix))]
            # file.write('#,' + ','.join(header) + '\n')

            # # Write matrix content
            for i, row in enumerate(matrix):
                # Add row index
                file.write(str(i) + ',')

            #     # Add matrix values
                file.write(','.join(map(lambda x: f"{x:.2f}", row)) + '\n')

    def get_min_distance(self,a,b):
        dist = 1e18
        for x in a:
            for y in b:
                dist= min(dist,self.matrix[x][y])
        return dist
    
    def generate_matrices(self):
        self.initialize()
        for i in range(self.dimension):
            for j in range(i):
                self.order.append([self.matrix[i][j], [j, i]])
        self.order.sort()
        while len(self.order) > 0:
            value = self.order[0][0]
            a = self.order[0][1][0]
            b = self.order[0][1][1]
            self.order.pop(0)
            is_diff = False

            if self.get(a) != self.get(b):
                self.union(a, b)
                is_diff = True
            if(is_diff):
                final = []
                for i in range(self.dimension):
                    if self.parent[i] == i:
                        final.append(self.groups[i])
            
                final.sort(key=lambda x: next(iter(x), None)) 
                
            
                final_mat = []
                for x in final:
                    row = []
                    for y in final:
                        row.append(self.get_min_distance(x,y))
                    final_mat.append(row)

                self.write_matrix_to_file(final_mat,final)
                print(final)
                for row in final_mat:
                    print(row)
                print()
                if len(final) == 1:
                    break


input_file = "/Users/apple/Desktop/JPMC/inp.txt"
output_file = "/Users/apple/Desktop/JPMC/q3.txt"
cluster = Clustering(output_file)
cluster.read_matrix_from_file(input_file)
cluster.generate_matrices()
