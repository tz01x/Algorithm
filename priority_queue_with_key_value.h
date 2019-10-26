#include <iostream>
#include <queue>
#include <limits>
	using namespace std;


	class node{
		public:
			int value;
			int key;
			node(int key,int value){
			    this->key=key;
				this->value = value;
			}
			node(){
			value=0;
			key=0;
			}
		};


	struct comp{
		bool operator()(const node& a,const node& b){
			return a.value>b.value;
		}
	};

	class Priority_Queue{
private:
    priority_queue <node, vector<node>,comp>pqi;
public:
   void push(int key,int value){
    	pqi.push(node(key,value));
    }
    int is_empty(){
    if(pqi.empty())
        return 1;
    return 0;
    }
    node pop(){
         node temp;
                if(!is_empty()){

            temp.key=pqi.top().key;
            temp.value=pqi.top().value;
            pqi.pop();

            }
            return temp;
        }



	};


//	int main() {
//		Priority_Queue q;
//		for(int i=0;i<5;i++){
//                int key,value;
//        cin>>key>>value;
//        node temp;
//
//            q.push(key,value);
//		}
//		while(!q.is_empty()){
//            node temp=q.pop();
//            cout<<temp.key<<"  "<<temp.value<<endl;
//		}
//
////		pqi.push(node(1,2));
////		pqi.push(node(2,5));
////		pqi.push(node(5,4));
////		pqi.push(node(6,1));
////		cout<<"  key :"<<<<endl;
////		cout<<"value :"<<pqi.top().value<<endl;
////		pqi.pop();
////        pqi.push(node(54,0));
////		cout<<"  key :"<<pqi.top().key<<endl;
////		cout<<"value :"<<pqi.top().value<<endl;
//		return 0;
//	}

