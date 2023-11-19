# 단순 연결 리스트(Singly Linked List)
연결의 형태가 한쪽 방향으로 전개되고, 시작과 끝이 분명히 존재하는 리스트 자료구조이다.<br>
<br>

## 📝 단순 연결 리스트의 ADT
이번에 공부해 볼 단순 연결 리스트의 ADT를 정리해 보도록 하겠다.<br>

**`void ListInit(List * plist);`**<br>
- 생성할 리스트의 초기화를 담당하는 기능이다.<br>
- 리스트 생성 후, 제일 먼저 호출해야 하는 기능이다.<br>
<br>

**`void LInsert(List * plist, LData data);`**<br>
- 리스트에 데이터를 저장한다. 매개변수 `data`에 전달된 값을 저장한다.<br>
<br>

**`int LFirtst(List * plist, Ldata * pdata);`**<br>
- 첫 번째 데이터가 `pdata`가 가리키고 있는 메모리에 저장된다.<br>
- 데이터의 참조를 위한 초기화가 이루어진다.<br>
- 참조 성공 시 `TRUE(1)`, 실패 시 `FALSE(0)`을 반환한다.<br>
<br>

**`int LNext(List * plist, Ldata * pdata);`**<br>
- 현재 참조되고 있는 데이터 다음으로 들어갈 데이터가 `pdata`가 가리키고 있는 메모리에 저장된다.<br>
- 순차적인 참조를 위해서 반복 호출이 가능하다.<br>
- 참조를 새로 시작하려면, 먼저 `LFirst`함수를 호출해야 한다. 데이터 탐색 및 참조의 기준은 항상 `LFist`함수이다.<br>
- 참조 성공 시 `TRUE(1)`, 실패 시, `FALSE(0)`을 반환한다.<br>
<br>

**`LData LRemove(List * plist);`**<br>
- `LFirst`혹은 `LNext`함수의 마지막 반환 데이터를 삭제한다.<br>
- 삭제된 데이터는 반환된다.<br>
- 마지막 반환 데이터를 삭제하므로 연이은 반복호출은 허용하지 않는다.<br>
<br>

**`int LCount(List * plist);`**<br>
- 리스트에 저장된 데이터의 개수를 반환한다.<br>
<br>

**`void SetSortRule(List * plist, int (*comp)(LData d1, LData d2);`**
- 리스트의 정렬의 기준이 되는 함수를 등록한다.<br>
<br>

## 더미 노드(Dummy Node) 기반의 단순 연결 리스트

### 새 노드의 추가 위치에 따른 장점과 단점
링크드 리스트의 새 노드의 추가 위치로는, 다음 2가지 선택지가 존재하며, 각 종류마다 장/단점이 존재한다.<br>

- #### 새 노드를 연결 리스트의 머리에 추가하는 경우
  장점 : 포인터 변수 `tail`이 불필요하다.<br>
  > 새로운 노드를 꼬리에 추가하는 경우, 새로 추가하고자 하는 노드를 링크드 리스트의 마지막 노드에 연결하여 추가하는 것이기 때문에,<br>
  > 이 마지막 노드를 가리키는 포인터 변수 `tail`이 필요하다.<br>
  > 하지만, 이러한 포인터 변수 `tail`을 유지하기 위해서 넣어야할 부가적인 코드들이 번거롭게 느껴질 수 있으며, 리스트 자료구조는<br>
  > 저장된 순서를 유지해야 하는 자료구조가 아니다. 

  <br>

  단점 : 저장된 순서를 유지하지 않는다.<br>
   
- 



