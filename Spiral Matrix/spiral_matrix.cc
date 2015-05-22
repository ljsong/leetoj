//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int> >& matrix) {
//        vector<int> nums;
//
//        if(matrix.size() == 0 || matrix[0].size() == 0) {
//            return nums;
//        }
//
//        int ix = 0, jx = 0;
//        int row = matrix.size(), column = matrix[0].size();
//        int lbrow = ix, lbcolumn = jx;            // lb means lower bound
//        int steps = 0;
//        while(lbrow < row && lbcolumn < column) {
//            if(steps == 0) {
//                traversal(jx, row, matrix[ix], nums);
//                steps++;
//            } else if(steps == 1) {
//                vector<int> col_vec;
//                get_column(matrix, --jx, 0, col_vec);
//                traversal(++ix, column, col_vec, nums);
//                steps++;
//            } else if(steps == 2) {
//                traversal(--jx, lbcolumn, matrix[--ix], nums);
//                steps++;
//            } else if(steps == 3) {
//                vector<int> col_vec;
//                get_column(matrix, ++jx, 0, col_vec);
//                if(--ix > lbrow) {
//                    traversal(--ix, lbrow + 1, col_vec, nums);
//                }
//                steps++;
//            } else {
//                ix = ++lbrow;
//                jx = ++lbcolumn;
//                --row;
//                --column;
//                steps = 0;
//            }
//        }
//        
//        return nums;
//    }
//
//private:
//    void get_column(vector<vector<int> >& matrix, int jx, int start, vector<int>& column) {
//        int row_size = matrix.size();
//
//        for(int kx = start; kx < row_size - start; ++kx) {
//            column.push_back(matrix[kx][jx]);
//        }
//    }
//
//    void traversal(int& ix, int bound, vector<int>& partial, vector<int>& nums) {
//        std::cout << "ix = " << ix << ", bound = " << bound << std::endl;
//       if(ix < bound) {
//           while(ix < bound) {
//               std::cout << "######nums push :" << partial[ix] << std::endl;
//               nums.push_back(partial[ix++]);
//           }
//       } else {
//           while(ix >= bound) {
//               std::cout << "$$$$$$nums push :" << partial[ix] << std::endl;
//               nums.push_back(partial[ix--]);
//           }
//       }
//    }
//};
//
//int main() {
//    Solution s;
//    int a[][4] = {{1, 2, 3, 4},
//                {5, 6, 7, 8}};
////                 {9, 10, 11, 12},
////                 {13, 14, 15, 16}};
//    vector<vector<int> > matrix;
//
//    for(int ix = 0; ix < 2; ++ix) {
//        matrix.push_back(vector<int>(&a[ix][0], &a[ix][0] + 4));
//    }
//    vector<int> nums = s.spiralOrder(matrix);
//    
//    vector<int>::iterator itr = nums.begin();
//    for(; itr != nums.end(); ++itr) {
//        std::cout << *itr << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
