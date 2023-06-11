class Node(object):
	def __init__(self, value):
		self.value = value
		self.next = None

def create_linkList(n):
	head = Node(1)
	ptr = head
	for i in range(2, n+1):
		newNode = Node(i)
		ptr.next= newNode
		ptr = newNode
	ptr.next = head
	return head

n = 1000 # total number of people
m = 2 # kill the second person
if m == 1: # if m==1 then the last person is nth person
	print(n)
else:
	head = create_linkList(n)
	ptr = None
	cur = head
	while cur.next != cur: # if points to itself then terminate
		for i in range(m-1):
			ptr =  cur
			cur = cur.next
		print(cur.value)
		ptr.next = cur.next
		cur.next = None
		cur = ptr.next
	print(cur.value)