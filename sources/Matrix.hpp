#include <string>
#include <string.h>
#include <iostream>
#include<vector>
#include <sstream>
using namespace std;

namespace zich{
  
    class Matrix
    {   
        private:
            int row;
            int col;
            std::vector<double> vec_to_mat;


        
        public:
            Matrix(std::vector<double> myvec, int ro, int co){
                if(ro*co != myvec.size()){
                    throw invalid_argument{"Matrix row*col mast be the vector size"};
                }
                if(ro<= 0 || co <=0){
                    throw invalid_argument{"Matrix row and col mast be positive"};
                }
                row = ro;
                col = co;
                vec_to_mat = myvec;
            }
            
            /*plus operator*/
            Matrix operator+();
            Matrix operator+(const Matrix &mat);
            Matrix operator+=(const Matrix &mat);
            
            /*minus operator*/
            Matrix operator-();
            Matrix operator-(const Matrix &mat);
            Matrix operator-=(const Matrix &mat);

            /*comper operator*/
            bool operator == (const Matrix &mat)const;
            bool operator <= (const Matrix &mat)const;
            bool operator >= (const Matrix &mat)const;
            bool operator < (const Matrix &mat)const;
            bool operator > (const Matrix &mat)const;
            bool operator != (const Matrix &mat)const;
            
            /*increes and decrees operator*/
            Matrix operator++();
            Matrix operator--();
            Matrix operator++(int n);
            Matrix operator--(int n);


            /*mult operator*/
            Matrix operator*(const Matrix &mat);
            Matrix operator*=(const Matrix &mat);
            Matrix operator*(const double num);
            Matrix operator*=(const double num);
            friend Matrix operator*(double n, Matrix &mat);

            /*input and output*/
            friend ostream &operator << ( ostream &output, const Matrix &mat);
            friend istream &operator >> ( istream  &input, Matrix &mat);

    };
    


    
}