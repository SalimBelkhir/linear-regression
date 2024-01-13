#include <iostream>
#include<vector>
#include<cmath>

//#define Eval(e) printf("%s=%d\n",#e,e)

using namespace std;
class Point {
public :
    void Init(){
        x=0;
        y=0;
    }
    void deplacer(float dx,float dy){
        x=x+dx ;
        y=y+dy ;
    }
    void afficher(){
        cout<<"("<<x<<","<<y<<")"<<endl ;
    }
    float getx(){return x ;}
    float gety(){return y ;}
private :
    float x;
    float y;
};
class linear_regression{
public :
    void addpoint(const Point& p){
        pts.push_back(p);
    }
    void regress_it(){
        size_t n = pts.size();
        if(n<2){
            cerr << "points insufficants pour la regresson." << endl;
            return;
        }
    float sumX=0.0 , sumY=0.0 , sumXY=0.0,sumX2=0.0;
        for( Point& p : pts){
            sumX += p.getx();
            sumY += p.gety();
            sumXY +=p.getx()*p.gety();
            sumX2 +=p.getx()*p.getx();
        }
        float moyX = sumX/n ;
        float moyY = sumY/n ;
        slope =(sumXY -n*moyX*moyY)/(sumX2-n*moyX*moyX);
        intercept=moyY-slope*moyX ;
    }
    float predict_y(float x){
        return slope*x + intercept ;
    }
private:
    vector<Point> pts ;
    float slope ;
    float intercept ;
};

int main()
{
    //cout << "Hello world!" << endl;
    //int i = 4 ;
    //Eval(2*i+7);
    Point p1,p2,p3 ;
    p1.Init();
    p1.afficher();
    p1.deplacer(2,4);
    p1.afficher();
    p2.deplacer(1,3);
    p3.deplacer(3,3);
    linear_regression y;
    y.addpoint(p1);
    y.addpoint(p2);
    y.addpoint(p3);
    y.regress_it();
    cout << y.predict_y(2) << endl;
    return 0;
}
