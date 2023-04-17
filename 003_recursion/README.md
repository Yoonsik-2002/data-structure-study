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
  
                                            
