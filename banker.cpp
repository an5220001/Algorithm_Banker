#include<bits/stdc++.h>
using namespace std;

int current[5][5], maximum_claim[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;
int request;
bool flag = true;


void NhapDulieuBang( int a, int b ) {
   	//nhap bang tai nguyen duoc phan bo
   	cout<<"Nhap bang Allocation: "<<endl;
     for (i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
   			cin>>current[i][j];
        }
     }
 
    cout<<"Nhap bang Max: "<<endl;
    for (i = 0; i < a; i++) {
         for(j = 0; j < b; j++) {
           
             cin>>maximum_claim[i][j];
        }
    }
}


void NhapVt(){
    cout<<"NHAP VECTOR HIEN THI SO LUONG PHIEN BAN CUA TUNG LOAI TAI NGUYEN:"<<endl;
    cout<<"Example: "<<endl;
    cout<<"Co 3 loai tai nguyen, tai nguyen A co 10 phien ban, tai nguyen B co 4 phien ban"<<endl;
    cout<<" tai nguyen C co 6 phien ban. =>> Nhap: 10   4   6"<<endl;
    cout<<endl<<"Claim vector:      ";
    for (i = 0; i < resources; i++) {
        cin>>maxres[i];
    }
   	cout<<endl;
}



void XuatBang ( int a , int b) {
	cout <<"Allocation table "<<endl;     
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
		 	cout<<current[i][j]<<" ";
		 }
		cout<<endl;
     }      
	cout<<"MAX table"<<endl; //bang yeu cau toi da
	for (i = 0; i < a; i++) {
         for (j = 0; j < b; j++) {
          	cout<<maximum_claim[i][j]<<" ";        
         }        
         cout<<endl;
    }
}


void XuatVector() {
    cout<<"Claim Vector: "; 
	for (i = 0; i < resources; i++) {
        cout<<  maxres[i]<<"  ";
	}
 	
 	cout<<endl;
	//tinh vector tong cua Allocation
    for (i = 0; i < processes; i++) {
         for (j = 0; j < resources; j++) {
             allocation[j] += current[i][j];
        }
    }
 
    cout<<"==> Allocated:  ";  // nguon luc duoc phan bo
	for (i = 0; i < resources; i++) {  
        cout<<allocation[i]<<" ";
    }
  	cout<<endl;
	for (i = 0; i < resources; i++) {
        available[i] = maxres[i] - allocation[i];
	}
    cout<<"==> Available:  "; //cac nguon co san
	 
	for (i = 0; i < resources; i++) {
     		cout<<available[i]<<" ";	 
	}
     cout<<endl<<endl;
}


void KiemTraTrangThai() {
    while (counter != 0) {
         safe = 0;
         for (i = 0; i < processes; i++) {
             if (running[i]) {
                 exec = 1;
                 for (j = 0; j < resources; j++) {
                     if (maximum_claim[i][j] - current[i][j] > available[j]) {
                         exec = 0;
                         break;
                     }
                 }
                 if (exec) {
                     cout<<endl<<"P"<< i <<" duoc thi hanh !"<<endl;	// dc thi hanh
					 running[i] = 0;
                     counter--;
                     safe = 1;
                     for (j = 0; j < resources; j++) {
                         available[j] += current[i][j];
                     }
                break;
                 }
             }
         }
        if (!safe) {
        	flag == false;
            cout<<"Cac quy trinh o trang thai khong an toan !!"<<endl; // cac quy trinh o trang thai khong an toan
            break;
         }
		else {
            cout<<"Quy trinh o trang thai an toan"<<endl;
 			cout<<"Available vector: ";
 
             for (i = 0; i < resources; i++) {                                 
                 cout<<available[i]<<" ";
             }         		
        		cout<<endl;
         }
     }
}


int main() {
	cout<<"Nhap so tien trinh: "; //nhap so quá trinh
	cin>> processes;
	cout<<endl;
	
	cout<<"Nhap so luong tai nguyen: "; //nhap so nguon
 	cin>>resources; 
 	cout<<endl;
 
    for (i = 0; i < processes; i++) {
         running[i] = 1;
         counter++;
    }
	NhapDulieuBang(processes, resources );
	
 	// nhap vector hien thi so luong phien ban cua tung loai tai nguyen
 	NhapVt();
	
	
 	cout<<endl<<"KET QUA:"<<endl;
 	
 	XuatBang(processes, resources); // xuat bang Allocation và bang MAX

	XuatVector();
	
	KiemTraTrangThai();
    
    if ( flag == true) cout<< "Trang thai an toan khong bi Deadlock !!!";
    else cout<<"Trang thai khong an toan vi mac phai Deadlock !!!";
	return 0;
}

