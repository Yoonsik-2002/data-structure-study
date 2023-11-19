# 단순 연결 리스트(Singly Linked List)
연결의 형태가 한쪽 방향으로 전개되고, 시작과 끝이 분명히 존재하는 리스트 자료구조이다.<br>
<br>

### 단순 연결 리스트의 ADT
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
- 순차적인 참조를 위해서 반복 호출이 가능하다.
- 

