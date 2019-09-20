#include <stdio.h>
#include <stdlib.h>


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
void Find( int target ){


// 設一數字 divisor 為開始除數
// 設計一個叫做 factor 的陣列 存放所有因數
// 設 i 作為計算陣列之數字
// 設 times 當作迴圈次數
int i = 0 ;
unsigned long long factor[99999] ;
unsigned long long divisor = 1 ;
int times = 0 ;

//在小於等於原數的情況下持續找因數
while( divisor <= target ){
  if ( target % divisor == 0){
    factor[i] = divisor ;
    times++ ;
    i++ ;
  }
  divisor ++ ;

}


// 若陣列大小為代表只有本身跟 1 兩個因數 印出
if ( i == 2 ){
    printf(" = %llu * %llu \n", factor[0], factor[1]  ) ;
}

//有超過兩個因數
else {
  // 設 num1 num2 存放最終因數 並設 t 為目前函數進行地步 n 是用來算減掉的次數
  int t = 0 ;
  int n = 1 ;
  unsigned long long num1 = factor[0] ;
  unsigned long long num2 = factor[i-1];

  // 在不為空陣列的情況下 找出

  // 偶數個因數
  if ( i%2 == 0 && i-1-n > n ){
    num1 = factor[i/2];
    num2 = factor[i/2+1] ;
  }

  //奇數個因數
  if (i%2 != 0){
    num1 = num2 = factor[ i/2 ] ;
  }



  printf(" = %llu * %llu\n", num1, num2 ) ;

}



} // Find


// 此為一可以找出費氏數列的函式
unsigned long long Fibonacci( unsigned long long num1, unsigned long long num2 ) {
  unsigned long long backword = 1 ;

  backword = num1 + num2 ;

  printf("所求費氏數字:%llu", backword );

  Find( backword ) ;

  return backword ;

} // Fibonacci

// 此為一個執行遞迴的函式
void Process( int last, int now, unsigned long long first, unsigned long long second ){


    //把整個順序顛倒
    if( now <= last ){


      if( now == 1 ){
        printf("[ 1 ]所求費氏數字:1 = 1 * 1 次數: 1 次\n" ) ;
        Process( last, now = now + 1 , first, second ) ;
      }

      else if( now == 2 ){
        printf("[ 2 ]所求費氏數字:2 = 1 * 2 次數: 1 次\n" ) ;
        Process( last, now = now + 1 , first, second ) ;
      }
      else{
        printf("[ %d ]", now ) ;
        Process( last, now = now + 1, second, Fibonacci( first, second ) ) ;

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

while( command != 0 && command != 1 && command != 2 ){
  printf("Wrong Input , Please try again\n");
  scanf("%d", &command ) ;
}

// 判斷輸入指令 並判斷使用
if ( command == 1 || command == 2){

  if( command == 1) printf("Iterative generation\n\n") ;
  if( command == 2) printf("Recursive generatio\n\n") ;

  // 步驟一 請使用者輸入所求數字 並設為 target
  //
  int target = 0 ;
  printf("請輸入指定數字: ") ;
  scanf( "%d", &target ) ;

  // 步驟二 設定基本參數
  // FirstNum 和 SecNum 是費氏數列所用數字(迴圈)
  // firstNum 和 secNum 是費氏數列所用數字(遞迴)
  // now 則是記錄當前跑到哪一位數字
  // some 站存空間

  unsigned long long FirstNum = 1 ,SecNum = 2 ;
  int now = 1 ;
  unsigned long long some = 1 ;
  unsigned long long firstNum = 1 ,secNum = 2 ;

  // 步驟三 開始執行程序
  // 條件 再不大於 92 的情況下
  // 每次接印出目前數字

  if(command == 1){
    while( now <= target ){

      printf("[ %d ]", now ) ;

      if( now > 2 ){   //找費氏數字的過程、在1 2 之後才有數列
        some = SecNum ;
        SecNum = Fibonacci( FirstNum, SecNum ) ; // 費事數字
        FirstNum = some ;
      }
      else{
        if( now == 1) printf("所求費氏數字:%d = 1 * 1 次數: 1 次\n", now ) ;
        else printf("所求費氏數字:%d = 1 * 2 次數: 1 次\n", now ) ;
      }
      now++ ;
    }

    return 0;
  }


  else{
    Process( target, now, firstNum, secNum ) ;
    return 0 ;
  }

}

printf("Thanks for using ") ;



return 0 ;

}
