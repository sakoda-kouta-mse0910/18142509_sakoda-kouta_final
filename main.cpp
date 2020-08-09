//
//  main.cpp
//  18142509_迫田洸太_最終課題
//
//  Created by 迫田洸太 on 2020/08/04.
//  Copyright © 2020 迫田洸太. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


//クラスの定義　クラスを利用
struct PrimeFactorization {
//Privateとしてnumを宣言
private:
    unsigned long long num;
    
//Publicとして2つのアクセッサを宣言
public:
    //セッタ
    void setNum( unsigned long long newNum ) { num = newNum; }
    //ゲッタ
    auto getNum() { return num; }
};


//オブジェクトの作成
PrimeFactorization PF;


//素因数をVectorに格納する関数
auto storagePrimeFactor( unsigned long long l ) {
    //変数の宣言
    int i = 2;
    //Vectorの宣言
    vector<unsigned long long> primeFactorVec;
    //iがlより大きくなるまで繰り返す
    while ( l >= i ) {
        //lをiで割った余りが0ならば
        if ( l % i == 0 ) {
            //Vectorに格納し
            primeFactorVec.push_back( i );
            //lにlをiで割ったものを代入
            l /= i;
        }
        //lをiで割った余りが0でないならば
        else {
            //iをインクリメント
            i++;
        }
    }
    //Vectorを返す
    return primeFactorVec;
    }


//素因数分解を表示する関数
void displayPrimeFactorization( vector<unsigned long long> v1 ) {
    //Vectorのサイズが0ならば
    if ( v1.size() == 0 ) {
        //表示する
        cout <<"1は素因数分解できず，素数でもない.\n";
    }
    //Vectorのサイズが1ならば
    else if ( v1.size() == 1 ) {
        //表示する
        cout << PF.getNum() << "は素数です.\n";
    }
    //Vectorのサイズが2以上であれば
    else if ( v1.size() > 1 ) {
        //表示する
        cout << PF.getNum() << "を素因数分解すると" << PF.getNum() << " = ";
        
        //変数の宣言　valueは素因数　countは指数　の変数
        int value = 2;
        auto count = 0;
    
        //先頭から末尾までループ
        for ( size_t s = 0; s < v1.size(); ++s ) {
            
        //sがVectorの最後の要素の番号でない　かつ　Vectorのs番目の要素がvalueに等しい　ならば
        if ( s != v1.size() - 1 && v1[s] == value ) {
            //countをインクリメント
            ++count;
        }
            
        //sが0でない　かつ　countが0 ならば
        else if ( s != 0 && count == 0 ) {
            //valueをインクリメント
            ++value;
            //sにs-1を代入
            s = s - 1;
        }
            
        //Vectorのs番目の要素がvalueに等しくない　かつ　countが0　ならば
        else if ( v1[s] != value && count == 0 ) {
            //valueをインクリメント
            ++value;
            //sにs-1を代入
            s = s - 1;
        }
            
        //sがVectorの最後の要素の番号でない　かつ　Vectorのs番目の要素がvalueに等しくない　かつ　countが1 ならば
        else if ( s != v1.size() - 1 && v1[s] != value && count == 1 ) {
            //表示する
            cout << v1[s - 1] << " * ";
            //countに0を代入
            count = 0;
            //valueをインクリメント
            ++value;
            //sにs-1を代入
            s = s - 1;
        }
            
        //sがVectorの最後の要素の番号でない　かつ　Vectorのs番目の要素がvalueに等しくない　かつ　countが2以上　ならば
        else if ( s != v1.size() - 1 && v1[s] != value && count > 1 ) {
            //表示する
            cout << v1[s - 1] << "^" << count << " * ";
            //countに0を代入する
            count = 0;
            //valueをインクリメント
            ++value;
            //sにs-1を代入する
            s = s - 1;
        }
            
        //sがVectorの最後の要素の番号である　かつ　Vectorのs-1番目とs番目の要素が等しくない　かつ　countが1 ならば
        else if ( s == v1.size() - 1 && v1[s - 1] != v1[s] && count == 1 ) {
            //表示する
            cout << v1[s - 1] << " * " << v1[s];
        }
            
        //sがVectorの最後の要素の番号である　かつ　Vectorのs-1番目とs番目の要素が等しくない　かつ　countが2以上ならば
        else if ( s == v1.size() - 1 && v1[s - 1] != v1[s] && count > 1 ) {
            //表示する
            cout << v1[s - 1] << "^" << count << " * " << v1[s];
        }
            
        //sがVectorの最後の要素の番号である　かつ　Vectorのs-1番目とs番目の要素が等しい　ならば
        else if ( s == v1.size() - 1 && v1[s - 1] == v1[s] ) {
            //countをインクリメントし
            ++count;
            //表示する
            cout << v1[s] << "^" << count;
        }
    }
        cout << "と表せます．\n";
    }
}


//約数をVectorに格納する関数
auto storageDivisor( unsigned long long m ) {
    //変数の宣言
    int j = 1;
    //Vectorの宣言
    vector<unsigned long long> divisorVec;
    //jがmよりも大きくなるまで繰り返す
    while ( m >= j ) {
        //mをjで割った余りが0ならば
        if ( m % j == 0 ) {
            //jをVectorに格納
            divisorVec.push_back( j );
        }
        //jをインクリメント
        ++j;
    }
    //Vectorを返す
    return divisorVec;
}


//約数を表示する関数
void displayDivisor( vector<unsigned long long> v2, unsigned long long n ) {
    cout << n << "の正の約数は";
    //Vectorの宣言
    vector<unsigned long long> divisorVec;
    //変数の宣言　約数の合計を表す変数
    auto total = 0;
    
    //先頭から末尾までループ　イテレータを利用
    for ( auto k = v2.begin(); k != v2.end(); ++k ) {
        //kがnでないなら
        if ( *k != n ) {
        //表示する
        cout << *k << ",";
        }
        
        //kがnならば
        else {
            //表示する
            cout << *k;
        }
        //合計を計算する
        total += *k;
    }
    cout << "です．\n";
    
    //約数の合計が2nに等しければ
    if ( total == 2 * n ) {
        //表示する
        cout << "さらに" << n << "は完全数です．\n";
}
}


int main() {
    //変数の宣言
    unsigned long long newNum;
    
    cout << "素因数分解したい正の整数を入力してください．\n";
    cin >> newNum;
    
    //セッタの呼び出し
    PF.setNum( newNum );
    
    //2つのVectorの宣言
    auto v1 = storagePrimeFactor( PF.getNum() );
    auto v2 = storageDivisor( PF.getNum() );
    
    //2つの関数の呼び出し
    displayPrimeFactorization( v1 );
    displayDivisor( v2, PF.getNum() );
}
