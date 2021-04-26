<<선형큐

초기에 front와 rear는 -1을 가르킴

<<원형큐
항상 front는 비어있어야 함

* Enqueue 명령시(data삽입시) FULL인지 확인하는 절차 필요
   (rear+1) % MAX_SIZE = front 이면 값을 넣을 수 없음 (Queue FULL 발생)
-queue overflow
* Dequeue 명령시(data제거) (front==rear)이면 (Queue EMPTY 발생)

-queue underflow
공백상태 : front == rear
포화상태 : front % MAX_SIZE == (rear+1) % MAX_SIZE
공백상태와 포화상태를 구별하기 위해 하나의 공간은 항상 비워둠