## 재귀함수(Recursive Function)
재귀함수란 아래 예시 코드와 같이, 함수 내에서 자기 자신을 다시 호출하는 함수를 의미한다.
```c
void Recursive(void) 
{
  printf("Recursive Call!\n");
  Recursive(); // 자기 자신을 재호출
}
```
이때, '해당 함수가 완료되지도 않았는데 함수 중간에 해당 함수를 재호출 한다' 라는 것을 말 그대로 이해하는 것은 뭔가 쉽지 않다.<br>
그래서 다른 방식으로 이해해보려 한다.<br>

> Recursive 함수가 호출되면, Recursive 함수의 복사본을 만들어서 복사본이 실행되는 구조로 이해가 가능하다.

이러한 방식으로 접근하여 이해할 수 있는 이유는, 실제로 Recursive 함수를 호출하면, 해당 함수를 구성하는 명령어들은 메모리에 복사되어 이동하고<br>
이렇게 이동된 바이너리 코드(명령어)들을 CPU가 하나하나씩 실행하게 되기 때문이다.<br>
**때문에, Recursive 함수가 호출되면 해당 함수의 복사본을 만들어서 복사본이 실행되는 구조가 반복되는 형태로 이해가 가능하다!**<br>

하지만 위 예시코드에는 문제가 있다. 바로 이 재귀의 탈출조건이 존재하지 않아, 한번 호출하면 멈추지 않고 계속해서 호출되는 문제이다.<br>
해당 코드에 탈출조건을 만들어서 3번 호출하면 호출을 멈추도록 해 보겠다.<br>

```c
#include <stdio.h>

void Recursive(int num) 
{
  if(num <= 0) 
    return;
  printf("Recursive Call! %d\n", num);
  Recursive(num - 1);
}

void main()
{
  Recursive(3);
}
```
3(`num`)이 0이 될때까지 호출을 반복하고, `num`이 0 이 되면, 호출을 멈추도록 탈출조건을 만들어 보았다. 그럼, 해당 코드를 실행하면 어떻게<br>
작동하는지 알아보도록 하겠다.<br>

재귀함수를 호출하면 해당 함수의 복사본이 실행된다고 설명 했었다. 그래서, 한번 호출될 때마다 Copy1, Copy2 ... 이런식으로 이름을 붙이도록 하겠다.<br>
- #### Copy1
  ```c
  void Recursive(3)
  {
    if(num <= 0) 
      return;
    printf("Recursive Call! %d\n", num);
    Recursive(num - 1);
  }
  ```
  먼저 main()에서 `Recursive(3);` 을 통해 처음으로 Recursive(`3`) 함수가 호출되고, 해당 함수가 복사되어 **`Copy1`** 이 실행된다.<br>
  이때, 아직 `num`값은 3으로, 재귀함수의 탈출조건을 충족하지 못한다.<br>
  때문에 `Recursive(3 - 1);`이 실행되어 또 다시 Recursive 함수를 호출하게 된다.<br>
  
- #### Copy2
  ```c
  void Recursive(2)
  {
    if(num <= 0) 
      return;
    printf("Recursive Call! %d\n", num);
    Recursive(num - 1);
  }
  ```
  **`Copy1`** 에서 실행된 `Recursive(3 - 1);` 때문에 또 Recursive(`2`) 함수가 호출되고, 해당 함수가 복사되어 **`Copy2`** 가 실행된다.<br>
  이때, 아직 `num`값은 2로, 재귀함수의 탈출조건에 해당되지 않는다.<br>
  결국 `Recursive(2 - 1);` 이 실행되어 또 다시 Recursive 함수를 호출하게 된다.<br>
  
- #### Copy3
  ```c
  void Recursive(1)
  {
    if(num <= 0) 
      return;
    printf("Recursive Call! %d\n", num);
    Recursive(num - 1);
  }
  ```
  **`Copy2`** 에서 실행된 `Recursive(2 - 1);` 때문에 다시 Recursive(`1`) 함수가 호출되고, 해당 함수가 복사되어 **`Copy3`** 가 실행된다.<br>
  이때, 아직 `num`값은 1로, 재귀함수의 탈출조건을 만족하지 못한다.<br>
  또 `Recursive(1 - 1);` 이 실행되어 또 다시 Recursive 함수를 호출하게 된다.<br>
  
- #### Copy4
    ```c
  void Recursive(0)
  {
    if(num <= 0) 
      return;
    printf("Recursive Call! %d\n", num);
    Recursive(num - 1);
  }
  ```
  **`Copy3`** 에서 실행된 `Recursive(1 - 1);` 때문에 다시 Recursive(`0`) 함수가 호출되고, 해당 함수가 복사되어 **`Copy4`** 가 실행된다.<br>
  이때, `num` 값은 0으로, 해당 재귀함수의 탈출조전을 만족한다!<br>
  때문에 함수가 반환(`return;`)되기 시작하는데, **함수가 반환(`return;`)이 되면, 함수를 빠져나오고, 해당 함수가 호출되었던 지점으로 돌아가게 된다.**<br>
  
  그럼, 잘 생각해보자, **`Copy4`** 가 호출되었던 시점은 어디인가? 바로 **`Copy3`** 의 `Recursive(num - 1);` 이다.<br>
  그래서, **`Copy3`** 의 `Recursive(num - 1);` 로 이동하게 되는데, 이것은 **`Copy3`** 의 `Recursive(num - 1);`의 함수 호출이 완료되었다는 것을 의미한다.<br>
  
  그렇다면 **`Copy3`** 함수는 완료되었기 때문에 해당 함수를 벗어나게 되고, 이 함수가 호출되었던 시점인 **`Copy2`** 의 `Recursive(num - 1)`로 이동하게 된다. 
  결국에 이러한 과정을 반복하며 호출의 역순으로 함수가 반환되며 맨 처음에 해당 함수가 호출된 지점인 **`Copy1`** 에서 종료가 된다.<br><br>
  
> 재귀함수의 호출 순서 : `Recursive(3);` -> **`Copy1`** -> **`Copy2`** -> **`Copy3`** -> **`Copy4`**<br>
> 재귀함수의 반환 순서 : **`Copy4`** -> **`Copy3`** -> **`Copy2`** -> **`Copy1`** -> `Recursive(3)`<br>
> 
> **호출(복사되어서 실행)된 함수들이 자신이 호출되었던 지점으로 돌아가면서 반환됨!**

<br><br>


## 재귀함수의 활용
재귀함수를 이용하면 복잡한 알고리즘이나 자료구조의 문제를 단순화 하는것이 가능하다.<br>
이러한 재귀함수를 활용할 수 있는 경우는 **수학적 수식으로 표현이 가능한 경우(재귀적인 수학적 수식을 그대로 코드로 옮김.)** 와 **수학적 수식으로<br>
표현은 불가능하지만, 재귀적인 성격을 띄는 경우** 가 있다. 

먼저, *'수학적 수식으로 표현이 가능한 경우'* 를 살펴보도록 하겠다.<br><br>

### 수학적 수식으로 표현이 가능한 경우(팩토리얼, 피보나치 수열)
C언어는 함수의 재귀적 호출(함수 내에서 함수 자기자신을 재호출)이 허용되는 언어이다.<br>
때문에 우리는 재귀함수를 이용하여, **재귀적인 수학적 수식을 코드로 그대로 옮기는 것이 가능**하다.<br>
해당 case의 예시로, 재귀를 이용한 팩도리얼 값을 반환하는 함수와 피보나치 수열을 출력하는 함수를 만들어 보겠다.<br>

- #### 팩토리얼 값 반환함수 `Factorial`
  정수 n의 팩토리얼은 n!으로 표시하며, n!의 의미는 다음과 같다.<br>
  
  ```c
  n! = n * (n-1) * (n-2) * (n-3) * ... * 2 * 1
  3! = 3 * 2 * 1
  5! = 5 * 4 * 3 * 2 * 1
  5! = 5 * 4!
  
  n! = n * (n - 1)!
  ```
  다음과 같이, n!은 `n! * (n - 1)!` 으로 표현이 가능하다. 이를 이용하여, n팩토리얼 f(n)은 다음과 같은 수학적 수식으로 표현이 가능하다.<br>
  ![수식 이미지](https://user-images.githubusercontent.com/83572199/233331291-f04d1289-fa0c-4660-8a12-bec8014839a8.png)<br>
  0!을 의미하는 f(0)은 1을 반환하게 되고, 이는 해당 수식을 이용하여 만들 재귀함수의 탈출조건이 된다.<br>
  위 수식을 코드로 그대로 옮겨, 정수 n의 팩토리얼값을 반환해주는 함수 **`Factorial`** 을 만들어 보겠다.<br>
  
  ```c 
  int Factorial(int n)
  {
    if(n == 0) // Factorial 함수의 탈출조건
      return 1;
    else
      n * Factorial(n - 1);
  }
  ```
- #### n번째 피보나치 수열의 값을 출력하는 함수 `Fibonacci`
  피보나치 수열은 앞의 수 두개를 더하여 현재의 수를 만들어 가는 수열로, 아래 예시와 같이 표현된다.<br>
  (피보나치 수열의 조건 - `첫번째 수는 0, 두 번째 수는 1`, 그 다음부터는 `이전값 + 이전전값 = 현재값`)<br>
    
  ```c
  0, 1, 1, 2, 3, 5, 8, 13, 21, ...
  ```
  즉, `n번째 값 = (n - 1)번째 값 + (n - 2)번째 값` 이 성립 되며, 피보나치 수열의 n번째 값 f(n)은 다음과 같은 수학적 수식으로 표현이<br>
  가능하다.<br>
  ![수식 이미지 (1)](https://user-images.githubusercontent.com/83572199/233345307-e2191d4d-842c-4983-bbd3-60e257ae3418.png)<br>
  첫 번째 값을 의미하는 f(1)은 0을 반환하고, 두 번째 값을 의미하는 f(2)는 1을 반환한다. 그리고, 그 밖의 n 번째 값들은 `f(n - 1) + f(n - 2)`<br>
  수식을 통해 반환이 된다.<br>
  위 수식을 그대로 코드로 옮겨, n번째 피보나치 수열의 값을 출력해주는 **Fibonacci** 함수를 이용한 피보나치 수열 출력 프로그램을 만들어 보겠다. 
  ```c
  int Fibonacci(int n)
  {
    if(n == 1)
      return 0;
    else if(n == 2)
      return 1;
    else
      return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
  ```
  ```c
  main void()
  {
    int length, i;
    printf("Enter the length of the sequence\n");
    scanf("%d", &length);
    
    printf("-----Fibonacci Sequence!-----\n");
    for(i = 1; i <= length; i++) {
      printf("%d ", Fibonacci(i));
    }
  }
  ```
팩토리얼, 피보나치 수열과 같이 **재귀적인 수학적 수식으로 표현이 가능한 경우**에는 해당 수식을 그대로 코드로 옮기는 방식으로,<br>
간단히 재귀함수로 구현이 가능하다.<br><br>

### 수학적 수식으로 표현이 불가능한 경우(이진탐색 알고리즘의 재귀적 구현)
이전에 다루었던 팩토리얼과 피보나치 수열의 경우, 수식적으로 표현이 가능하여 해당 수식을 코드로 옮기기만 하면 <br>
재귀적으로 구현이 가능하였다.<br>
하지만, 이진탐색 알고리즘은 수식적으로는 표현이 불가능하다. 하지만, **해당 알고리즘의 논리 자체는 재귀적인 성격을<br>
띄기 때문에 재귀적 표현이 가능하다.**<br>

>이진탐색 알고리즘은 탐색 범위 중앙에 찾고자 하는 값인 `target`이 저장되어 있는지 확인하고, 저장되지 않았으면,<br>
해당 범위를 반으로 줄여서 다시 탐색을 시작한다.<br>

**이러한 작업을 `target`을 찾을 때까지 반복하여 수행한다.**<br>

즉, `'범위내 중앙값 확인, `target`과 일치하지 않을 시, 범위를 반으로 줄여 다시 탐색'` 이라는 동일한 패턴을 반복한다.<br>
이 **동일한 패턴을 반복 한다** 라는 것을 통해 해당 알고리즘이 논리적으로는 재귀적인 성격을 띈다는 것을 파악할 수 있다.<br>

이렇게 이진탐색 알고리즘이 재귀적으로 구현이 가능하다는 것을 알아 보았다. 그럼 먼저, 이진탐색 알고리즘이 종료되는 조건은 무엇이 있을까?<br>

바로, 범위내 중앙값과 `target`이 일치하여, `target`을 저장하고 있는 index값을 반환하는 경우와 끝까지 `target`을 찾지 못하여,<br>
`first`가 `last`보다 커지게 된 경우가 있을 것이다.<br><br>

그리고, 값을 찾지 못한 경우(중앙값과 `target`이 일치하지 않는 경우)로는 `target`이 `mid`보다 작은 경우와 `target`이 `mid`보다 큰 경우가 존재한다.<br>

- `target`이 `mid`보다 작은 경우에는 `last`의 값을 `mid - 1`로 수정하여 범위를 반으로 줄여, 다시 탐색을 수행한다.<br>
- `target`이 `mid`보다 큰 경우에는 `first`의 값을 `mid + 1`로 수정하여 범위를 반으로 줄여, 다시 탐색을 수행한다.<br>

이때, 이진탐색 알고리즘은 **`target`을 찾을 때 까지 (범위를 반으로 줄여 다시 탐색을 수행하는)해당 과정을 반복하게 된다.**<br>
때문에, 해당 부분을 재귀적으로 표현하는 것이 가능하게 되는 것이다!<br>

먼저, 해당 조건들을 가지고 이진탐색 알고리즘을 재귀적으로 구현한 함수 **`BSearchRecur`** 을 나타내면 다음과 같다.<br>
```c
int BSearchRecur(int ex_arr[], int first, int last, int target)
{
	int mid = (first + last) / 2;
	
	if(first > last)
		return -1;
	
	if(target == ex_arr[mid])
		return mid;
	else if(target < ex_arr[mid])
		return BSearchRecur(ex_arr, first, mid - 1, target);
	else
		return BSearchRecur(ex_arr, mid + 1, last, target);
}
```
```c
void main()
{
	int ex_arr[] = {1, 3, 5, 7, 9};
	int result, target;
	
	printf("Enter the target : ");
	scanf("%d", &target);
	
	result = BSearchRecur(ex_arr, 0, sizeof(ex_arr)/sizeof(int)-1, target);
	
	if(result == -1)
		printf("값을 찾지 못하였음\n");
	else
		printf("target을 저장하고 있는 index : %d\n", result);
}
```

<br><br>


## 하노이 타워
![hanoi-tower-intro](https://user-images.githubusercontent.com/83572199/233814303-7f3da79a-c246-4f5a-9943-53d8852dbbfe.png)<br>
- ##### 하노이 타워의 이해 - 
  다음과 같이, 기둥 `A`, `B`, `C` 가 존재하고, `A`에 있는 (크기가 다른)원반들을 `B`를 활용하여 `C`로 옮겨주어야 한다.<br>
  이때, 원반을 옮기는데에 있어 제약사항이 존재하는데, 해당 제약사항은 다음과 같다.<br>
  
  > - 원반은 한번에 하나씩만 옮길 수 있다.<br>
  > - 옮기는 과정에서, 작은 원반 위에 큰 원반이 올라가서는 안된다.<br>
<br>

이러한 하노이 타워를 해결하기 위해서는 다음과 같은 재귀의 특성을 떠올릴 수 있어야 한다.<br>
**`같은 패턴이 반복되는 문제의 경우, 한 패턴을 해결하면 재귀를 이용하여 뒤에 따르는 파생적인 문제(패턴)을 해결이 가능하다!`**<br>
이러한 재귀의 특성을 활용하여 문제를 해결해 보도록 하겠다.<br>














  
                                            
