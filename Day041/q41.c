import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, data):
        new_node = Node(data)
        if self.tail is None:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node

    def dequeue(self):
        if self.head is None:
            return -1
        
        temp = self.head
        self.head = self.head.next
        
        if self.head is None:
            self.tail = None
            
        return temp.data

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    n = int(input_data[0])
    q = Queue()
    
    idx = 1
    operations_count = 0
    while operations_count < n and idx < len(input_data):
        op = input_data[idx]
        
        if op.lower() == "enqueue":
            val = int(input_data[idx + 1])
            q.enqueue(val)
            idx += 2
        elif op.lower() == "dequeue":
            print(q.dequeue())
            idx += 1
            
        operations_count += 1

if __name__ == "__main__":
    solve()