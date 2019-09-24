#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/* 9/11周 資料結構作業 蘇世界 , 劉宜鑫

   目標: 使用迴圈 和 遞迴 練習

   (1). 輸出從 1 開始的費氏數列到 N
   (2). 找出數字中差值最小的因數
   (3). 相乘兩因數並給予編號

   輸出:
   (1). 顯示前N個數字
   (2). 相乘的數字大小
   (3). 執行次數

*/


// 此為的一找出數列中的最小因數差之函數
void Find( unsigned long long target ){


// 設一數字num 為target 的開根號數
unsigned long long num = sqrt(target) ;

// 設一數字 times 為計算迴圈數的數字

unsigned long long times = 0 ;

while( target % num != 0 ){
    num ++ ;
    times++ ;
}

 unsigned long long one = num ;
 unsigned long long two = target / num ;

 if( one > two ){
    one = target / num ;
    two = num ;
 }

 if ( times == 0 ) times = 1 ;

  printf(" = %llu * %llu ",  one, two ) ;

  printf(" 迴圈次數: %d 次 ", times  ) ;



} // Find


// 此為一可以找出費氏數列的函式
unsigned long long Fibonacci( unsigned long long num1, unsigned long long num2 ) {
  unsigned long long backword = 1 ;

  backword = num1 + num2 ;

  printf("所求費氏數字:%llu", backword );

  Find( backword ) ;

  return backword ;

} // Fibonacci

// 此為一可以找出費氏數列的函式 多了計遞迴次數
unsigned long long Fibonacci2( unsigned long long num1, unsigned long long num2, unsigned long long times ) {
  unsigned long long backword = 1 ;

  backword = num1 + num2 ;

  printf("所求費氏數字:%llu", backword );

  Find( backword ) ;

  printf("遞迴次數: %llu 次 \n", times ) ;

  return backword ;

} // Fibonacci

// 此為一個執行遞迴的函式
void Process( int last, int now, unsigned long long first, unsigned long long second, unsigned long long times){


    //把整個順序顛倒
    if( now <= last ){

      if( now == 1 ){
        printf("[ 1 ]所求費氏數字:1 = 1 * 1  迴圈次數: 1 次 遞迴次數: 1 次 \n" ) ;
        Process( last, now = now + 1 , first, second, times = times + 1) ;
      }

      else if( now == 2 ){
        printf("[ 2 ]所求費氏數字:2 = 1 * 2  迴圈次數: 1 次 遞迴次數: 2 次 \n" ) ;
        Process( last, now = now + 1 , first, second, times = times + 1 ) ;
      }
      else{
        printf("[ %d ] ", now ) ;

        Process( last, now = now + 1, second, Fibonacci2( first, second, times ), times = times + 1 ) ;

      }
    }

}


int main()
{

printf("**Fibonacci Series Generator**\n");
printf("* 0. Quit                    *\n");
printf("* 1. Iterative generation    *\n");
printf("* 2. Recursive generatio     *\n");
printf("******************************\n");
printf("Input a command(0,  1,  2)\n");



// 請使用者先輸入所想要使用指令 若錯誤則重試一次
//
int command ;
   
scanf("%d", &command) ;

while( command != 0 ) {   
while( command != 0 && command != 1 && command != 2 ){
  printf("Wrong Input , Please try again\n");
  scanf("%d", &command ) ;
}
  if( command == 1) printf("Iterative generation\n\n") ;
  if( command == 2) printf("Recursive generatio\n\n") ;


// 判斷輸入指令 並判斷使用
if ( command == 1 || command == 2){

  // 步驟一 請使用者輸入所求數字 並設為 target
  //
  int target = 0 ;
  printf("請輸入一個小於92的數字: ") ;
  scanf( "%d", &target ) ;


  while( target > 92 ) {
    printf("錯誤輸入 請重新嘗試一遍:  \n") ;
    scanf( "%d", &target ) ;

  }
   
  // 步驟二 設定基本參數
  // FirstNum 和 SecNum 是費氏數列所用數字(迴圈)
  // firstNum 和 secNum 是費氏數列所用數字(遞迴)
  // now 則是記錄當前跑到哪一位數字
  // some 站存空間
  // times 季遞迴次數

  unsigned long long FirstNum = 1 ,SecNum = 2 ;
  int now = 1 ;
  unsigned long long times = 0 ;
  unsigned long long some = 1 ;
  unsigned long long firstNum = 1 ,secNum = 2 ;

  // 步驟三 開始執行程序
  // 條件 now 再不大於 92 的情況下
  // 每次接印出目前數字

  // 迴圈
  if(command == 1){
    while( now <= target ){

      printf("[ %d ]", now ) ;

      if( now > 2 ){   //找費氏數字的過程、在1 2 之後才有數列
        some = SecNum ;
        SecNum = Fibonacci( FirstNum, SecNum ) ; // 費事數字
        FirstNum = some ;
        printf("\n") ;
      }
      else{
        if( now == 1) printf("所求費氏數字:%d = 1 * 1 迴圈次數: 1 次\n", now ) ;
        else printf("所求費氏數字:%d = 1 * 2 迴圈次數: 1 次\n", now ) ;
      }
      now++ ;
    }


  }

  // 遞迴
  else{
    Process( target, now, firstNum, secNum, times ) ;

  }

}


printf("Input a command(0,  1,  2)\n");
scanf("%d", &command) ;

}
if( command == 0 ){
  printf("Thanks for using ") ;
  return 0 ;
}   
}
