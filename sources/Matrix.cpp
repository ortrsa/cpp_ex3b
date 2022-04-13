#include "Matrix.hpp"
using namespace std;
using namespace zich;

const int LOW = 47;
const int HIGE = 58;

namespace zich{
            
  
            /*plus operator*/
            Matrix Matrix::operator+(){
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    this->vec_to_mat.at(i) *= 1;
                }
                 
                return(*this);
            }
            Matrix Matrix::operator+(const Matrix &mat){
                // if row and col dosnt in the same size
                if(this->col != mat.col || this->row != mat.row){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                
                //make new vector and add add the matrixs to it. 
                std::vector<double> temp;
                size_t j = 0;
                for (size_t i = 0 ; i <this->vec_to_mat.size(); i++) {
                    temp.push_back(this->vec_to_mat.at(i)+ mat.vec_to_mat.at(j));
                    j++;
                }
                // make new matrix to return
                Matrix ans(temp, this->row, this->col);
                return(ans);
            }
            Matrix Matrix::operator+=(const Matrix &mat){
                // make all of the aritmatic function on "this" matrix
                if(this->col != mat.col || this->row != mat.row){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                   this->vec_to_mat.at(i) += mat.vec_to_mat.at(i);
                }
                
                
                return(*this);
            }
            
            /*minus operator*/
            Matrix Matrix::operator-(){
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    this->vec_to_mat.at(i) *= -1;
                }
                 
                return(*this);
            }
            Matrix Matrix::operator-(const Matrix &mat){
                // throw if the matrixs dosnt fit
                if(this->col != mat.col || this->row != mat.row){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                std::vector<double> temp;
                size_t j = 0;
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    temp.push_back(this->vec_to_mat.at(i)- mat.vec_to_mat.at(j));
                    j++;
                }
                Matrix ans(temp, this->row, this->col);
                // return new matrix
                return(ans);
            }
            Matrix Matrix::operator-=(const Matrix &mat){
                // make all of the aritmatic function on "this" matrix
                if(this->col != mat.col || this->row != mat.row){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                   this->vec_to_mat.at(i) -= mat.vec_to_mat.at(i);
                }
                
                return(*this);
            }



            /*comper operator*/
            bool Matrix::operator == (const Matrix &mat)const{
                if(this->col != mat.col || this->row != mat.row){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                    // comper vectors and matrix size
                    if(this->vec_to_mat == mat.vec_to_mat){
                        return(true);
                    }
                    
                return(false);
            }
            bool Matrix::operator <= (const Matrix &mat)const{
                if(this->col != mat.col || this->row != mat.row || this->vec_to_mat.size()!= mat.vec_to_mat.size()){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                // counter for the matrix sum.
                double thisum =0;
                double matsum =0;
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    thisum += this->vec_to_mat.at(i);
                    matsum += mat.vec_to_mat.at(i);
                }
                

                if(thisum <= matsum){
                    return(true);
                }
                    
                return(false);
            }
            bool Matrix::operator >= (const Matrix &mat)const{
                // check if the matrix in the same size
                if(this->col != mat.col || this->row != mat.row || this->vec_to_mat.size()!= mat.vec_to_mat.size()){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                // sum matrix and check the condition
                double thisum =0;
                double matsum =0;
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    thisum += this->vec_to_mat.at(i);
                    matsum += mat.vec_to_mat.at(i);
                }
                

                if(thisum >= matsum){
                    return(true);
                }
                    
                return(false);
            }
            bool Matrix::operator < (const Matrix &mat)const{
                if(this->col != mat.col || this->row != mat.row || this->vec_to_mat.size()!= mat.vec_to_mat.size()){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                double thisum =0;
                double matsum =0;
                // sum matrixs and compere
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    thisum += this->vec_to_mat.at(i);
                    matsum += mat.vec_to_mat.at(i);
                }
                

                if(thisum < matsum){
                    return(true);
                }
                    
                return(false);
            }
            bool Matrix::operator > (const Matrix &mat) const {
                if(this->col != mat.col || this->row != mat.row || this->vec_to_mat.size()!= mat.vec_to_mat.size()){
                    throw invalid_argument{"Matrix mast be is the same size"};
                }
                double thisum =0;
                double matsum =0;
                // sum matrixs and compere
                for (size_t i = 0; i < this->vec_to_mat.size(); i++)
                {
                    thisum += this->vec_to_mat.at(i);
                    matsum += mat.vec_to_mat.at(i);
                }
                

                if(thisum > matsum){
                    return(true);
                }
                    
                return(false);
            }
            bool Matrix::operator != (const Matrix &mat) const {
                if(*this==mat){
                    return(false);
                }
                
                return(true);
            }
            
            /*increes and decrees operator*/
            Matrix Matrix::operator++(){
                vector<double> ones((size_t)(this->row*this->col),1);
                Matrix temp(ones, this->row, this->col);
                *this += temp;
                return(*this);
            }
            Matrix Matrix::operator--(){
                vector<double> ones((size_t)(this->row*this->col),-1);
                Matrix temp(ones, this->row, this->col);
                *this += temp;
                return(*this);
            }
            Matrix Matrix::operator++(int n){
                
                Matrix ans(this->vec_to_mat, this->row, this->col);
                ++*this;
                return ans;
            
            }
            Matrix Matrix::operator--(int n){
                Matrix ans(this->vec_to_mat, this->row, this->col);
                --*this;
                return ans;
            }


            /*mult operator*/
            Matrix Matrix::operator*(const Matrix &mat){
                // check if we can mult the matrixs
                if (this->col!= mat.row)
                {
                    throw invalid_argument{"mast be is size: (mXn)*(mXt) "};
                }
                // Initializing elements of matrix mult to 0.
                size_t vecsize = (size_t)(this->row)*(size_t)(mat.col);
                std::vector<double> temp(vecsize,0);
                
                
                // Multiplying matrix a and b and storing in vector
                for(size_t i = 0; i < this->row; i++){
                    for(size_t j = 0; j < mat.col; j++){
                        for(size_t k = 0; k < this->col; k++)
                        {
                            temp.at(i*(size_t)mat.col + j) += this->vec_to_mat[i*(size_t)this->col + k] * (size_t)mat.vec_to_mat[k*(size_t)mat.col + j];
                        }}}

                Matrix ans(temp,this->row, mat.col);
                return(ans);
            }
            Matrix Matrix::operator*=(const Matrix &mat){
                if (this->col!= mat.row)
                {
                    throw invalid_argument{"mast be is size: (mXn)*(mXt) "};
                }
                size_t vecsize = (size_t)(this->row)*(size_t)(mat.col);;
                std::vector<double> temp(vecsize,0);
                // for(int i = 0; i < this->row*mat.col ; i++)
                //     {
                //         temp.push_back(0);
                //     }
                for(size_t i = 0; i < this->row; i++){
                    for(size_t j = 0; j < mat.col; j++){
                        for(size_t k = 0; k < this->col; k++)
                        {
                            
                            temp.at(i*(size_t)mat.col + j) += this->vec_to_mat[i*(size_t)this->col + k] * mat.vec_to_mat[k*(size_t)mat.col + j];
                        }
                    }
                }
                this->vec_to_mat = temp;
                this->col = mat.col; 
                return *this;
            };

            Matrix Matrix::operator*(const double num){
                // Initializing elements of matrix mult to 0.
                std::vector<double> temp(this->vec_to_mat.size(), 0);
                
                
                // Multiplying matrix a and b and storing in array mult.
                for(size_t i = 0; i < this->vec_to_mat.size(); i++){
                    temp.at(i) = this->vec_to_mat.at(i) * num;
                }
                        
                Matrix ans(temp,this->row, this->col);
                return(ans);
            }
            Matrix Matrix::operator*=(const double num){
                for(size_t i = 0; i < this->vec_to_mat.size(); i++){
                    this->vec_to_mat.at(i) *= num;
                }
                
                return(*this);
            }

            Matrix operator*(double num, Matrix& mat){
                // Initializing elements of matrix mult to 0.
                std::vector<double> temp(mat.vec_to_mat.size(), 0);
                
                
                // Multiplying matrix a and b and storing in array mult.
                for(size_t i = 0; i < mat.vec_to_mat.size(); i++){
                    temp.at(i) = mat.vec_to_mat.at(i) * num;
                }
                        
                Matrix ans(temp,mat.row, mat.col);
                return(ans);
            }

            /*input and output*/
            std::ostream &operator << ( std::ostream &output, const Matrix &mat){
                for (size_t i = 0; i < mat.row; i++)
                {
                    output<< "[";
                    for (size_t j = 0; j < mat.col; j++)
                    {
                        output<<mat.vec_to_mat[(size_t)mat.col*i + j];
                        if(j<mat.col-1){
                            output<< " ";
                        }
                    }
                    output<< "]";
                    if(i < mat.row-1){
                        output<< "\n";
                    }
                }
                
                
                return(output);
            }
            std::istream &operator>>(std::istream &input,Matrix &mat){
                
                string matstring;
                int row = 0;
                int col =1;
                int counter =0;
                bool inq = false;
                getline(input, matstring);
                stringstream strim = stringstream(matstring);
                vector<double> vec;

                char a = '0';
                // check if the string is formated
                if(strim.peek() != '['){
                    throw invalid_argument{"string need to be formmated"};
                }
                if(matstring.back() != ']'){
                    throw invalid_argument{"string need to be formmated"};
                }
                // if the string dosnt end 
                while(!strim.eof()){
                    string temp;
                    a = strim.get();
                    // check there is only acceptable char
                    if(a != '\n' && a != ' ' && a != '[' && a != ']' && a != '.' && a != ',' && (a >= HIGE || a<=LOW) && !strim.eof() ){
                        throw invalid_argument{"string need to be formmated"};
                    }
                    // count rows
                    if(a == '['){
                        row +=1;
                        temp = "";
                        inq = true;
                        
                    // count columns
                    }else if(a == ' '){
                        col+=1;
                        temp = "";
                        
                    }else if(a == ']'){
                        inq =false;
                    }
                    // check the numbers are in the []
                    if(!inq && (a < HIGE && a>LOW)){
                        throw invalid_argument{"string need to be formmated"};
                    }
                    if((a < HIGE && a>LOW) || a == '.'){
                        
                        while((a < HIGE && a>LOW) || a == '.'){
                            temp+= a;
                            a = strim.get();
                            if(a == ' '){
                                col+=1;
                            }
                            if(a == ']'){
                                inq =false;
                            }
                        }
                        // Make string to double and add to vec  
                        vec.push_back(std::stod(temp));
                    
                      
                    }
                  
                    
                }
                if(row == 0){
                    throw invalid_argument{"There is 0 rows"};
                }
                col = (col - row)/row + 1 ;
                mat = Matrix(vec,row,col);
                return(input);
            }


        
    };
    


