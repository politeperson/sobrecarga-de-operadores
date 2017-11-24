#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool ascendente(int x, int y){
    if(x < y)
        return true;
    else
        return false;
}
bool descendente(int x, int y){
    if(x > y)
        return true;
    else
        return false;
}

template <typename T>
class Matrix {

    private:
        // Square matrix
        T **matrix;
        int f,c;
    public:
        // Constructor
        Matrix();
        // Constructor overload
        Matrix(const int F , const int C , const T value);
        Matrix(const int F , const int C);
        // Destructor
        ~Matrix();
        // Value  position he matrix
        T get(const int row, const int col) const;
        // Assigning a position value to the matrix
        void set(const int row, const int col, const T value);
        void build_dinamic();
        void build_static(const T value);
        // Show matrix
        void show(const string matriz);
        int get_f(){
            return f;
        }
            
        int get_c(){
            return c;
        }

        void resize(const int F , const int C);
        // Operator overloading
        Matrix operator+(const Matrix<T> matriz);//esta sera mi funcon para devolver las suma de ambas
        Matrix operator-(const Matrix<T> matriz);//"          "           la resta
        Matrix operator*(const Matrix<T> matriz);//"          "           la multiplicaión
        Matrix operator<(const Matrix<T> matriz);//"          "      el menor de ambos i , j
        Matrix operator>(const Matrix<T> matriz);//"          "      el mayor de ambos i , j
        Matrix operator%(const Matrix<T> matriz);//funcion para devolver el promedio de ambos i , j
        void operator=(const Matrix<T> matriz);//asignar los mismos valores 
        void ordenar(char mode);
};

template <typename T>
void Matrix<T>::ordenar(char mode){
    vector<T> v;
    if(mode == '<'){
        for(int i = 0; i < f; i++)
            for(int j = 0; j < c; j++)
                v.push_back(matrix[i][j]);
        sort(v.begin() , v.end() , descendente);
        for(int i = 0; i < f; i++)
            for(int j = 0; j < c; j++)
                matrix[i][j] = v[i*c + j];
        
    }
    else if(mode == '>'){
        for(int i = 0; i < f; i++)
            for(int j = 0; j < c; j++)
                v.push_back(matrix[i][j]);
        sort(v.begin() , v.end() , ascendente);
        for(int i = 0; i < f; i++)
            for(int j = 0; j < c; j++)
                matrix[i][j] = v[i*c + j];      
    }
    else{
        cout << "solo hay ascendente y descendente" << endl;
    }
}

template <typename T>
void Matrix<T>::build_static(const T value){
   for (int i = 0; i < f; ++i){
        for (int j = 0; j < c; ++j){
            matrix[i][j] = value;
        }
    }
}    

template <typename T>
void Matrix<T>::resize(const int F , const int C){
    for (int i = 0; i < F; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;
    f = F;
    c = C;

    matrix = new T *[F];
    for(int i = 0; i < F; i++){
        matrix[i] = new T [C];
    }
}

template <typename T>
Matrix<T>::Matrix(){}

template <typename T>
Matrix<T>::Matrix(const int F , const int C , const T value){
    f = F;
    c = C;
    matrix = new T *[F];
    for(int i = 0; i < F; i++){
        matrix[i] = new T [C];
    }
    for(int i = 0; i < F; i++){
        for(int j = 0; j < C; j++){
            matrix[i][j] = value;        
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const int F , const int C){
    f = F;
    c = C;
    matrix = new T *[F];
    for(int i = 0; i < F; i++){
        matrix[i] = new T [C];
    }
}

template <typename T>
Matrix<T>::~Matrix(){}

template <typename T>
T Matrix<T>::get(const int row, const int col) const
{
    return matrix[row][col];
}

template <typename T>
void Matrix<T>::set(const int row, const int col, T value)
{
    this->matrix[row][col] = value;
}


template <typename T>
void Matrix<T>::build_dinamic()
{
   for (int i = 0; i < this->f; ++i){
        for (int j = 0; j < this->c; ++j){
            T tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
        }
   }
}

template <typename T>
void Matrix<T>::show(const string matriz)
{
    cout << matriz << endl << endl;

   for(int i = 0; i < f ; i++)
    {
       for(int j = 0; j < c ; j++)
        {
            cout << "  " << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> matriz)
{
   Matrix<T> result(this->f,this->c);

   for(int i = 0; i < this->c ; i++)
    {
       for(int j = 0; j < this->c ; j++)
        {
            T sum = this->matrix[i][j] + matriz.get(i, j);
            result.set(i , j, sum);
        }
    }

    return result;   
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> matriz)
{
    Matrix <T> result(this->f , this->c);

   for(int i = 0; i < this->f ; i++)
    {
       for(int j = 0; j < this->c ; j++)
        {
            T resto = this->matrix[i][j] - matriz.get(i, j);
            result.set(i , j, resto);
        }
    }

    return result;
}

template<typename T>
void Matrix<T>::operator=(const Matrix<T> matriz)
{
   for(int i = 0; i < this->f ; i++)
    {
       for(int j = 0; j < this->c ; j++)
        {
            this->matrix[i][j] = matriz.get(i, j);
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator<(const Matrix<T> matriz)
{
    Matrix<T> result(this->f,this->c);

   for(int i = 0; i < this->f ; i++)
    {
       for(int j = 0; j < this->c ; j++)
        {
            T resto = min(this->matrix[i][j] , matriz.get(i, j));
            result.set(i , j, resto);
        }
    }

    return result;
}

template <typename T>//ME DEVUELVE EL MAYOR DE AMBAS I,J DE CADA MATRIZ
Matrix<T> Matrix<T>::operator>(const Matrix<T> matriz)
{
    Matrix<T> result(this->f,this->c);

   for(int i = 0; i < this->f ; i++)
    {
       for(int j = 0; j < this->c ; j++)
        {
            T resto = max(this->matrix[i][j] , matriz.get(i, j));//USO MAX DE LA LIBRERIA ALGORITHM
            result.set(i , j, resto);
        }
    }

    return result;
}

template<typename T>//PROMEDIO DE AMBOS I,J
Matrix<T> Matrix<T>::operator%(const Matrix<T> matriz)
{
    Matrix<T> result(this->f,this->c);

   for(int i = 0; i < this->f ; i++)
    {
       for(int j = 0; j < this->c ; j++)
        {
            T resto = (this->matrix[i][j] + matriz.get(i, j)) / 2;
            result.set(i , j, resto);
        }
    }

    return result;
}

template<typename T>//MULTIPLICACION DE MATRICES
Matrix<T> Matrix<T>::operator*(Matrix<T> matriz)
{
    Matrix <T> result(f , matriz.get_c() , 0);

    for(int i = 0; i < f; i++){
        for(int j = 0; j < matriz.get_c(); j++){
            for(int k = 0; k < c; k++){
                result.set(i , j , result.get(i ,j) + matrix[i][k] * matriz.get(k , j));
            }
        }
    }
    return result;   
}


/*
ESTA PARTE LA DEJO PORQUE SINO ABRIA AMBIGUEDAD EN LA SOBRECARGA DE OPERADORES
bool operator>(const Matrix<T> matriz);//retornar true si se cumple a > b?
bool operator<(const Matrix<T> matriz);//retornar true si se cumple a < b?

template<typename T> 
bool Matrix<T>::operator<(const Matrix<T> matriz)
{
   for(int i = 0; i < f ; i++)
    {
       for(int j = 0; j < c ; j++)
        {
            if(matrix[i][j] > matriz.get(i, j))
                return false;
        }
    }

    return true;
}





template<typename T>
bool Matrix<T>::operator>(const Matrix<T> matriz)
{
   for(int i = 0; i < f ; i++)
    {
       for(int j = 0; j < c ; j++)
        {
            if(matrix[i][j] < matriz.get(i, j))
                return false;
        }
    }

    return true;
}*/