# FIFO Queue (FQueue) Project

This project implements a **FIFO Queue (FQueue)** in C++, using a singly linked list. It includes queue operations, memory management, and exception handling.

---

## Components

### `FQInfo` Structure

- **Fields:**
  - `int nKey`: Element key.
  - `int* p`: Dynamic array of two integers.
- **Constructor:** Initializes with an `int`.
- **Virtual Destructor:** Ensures proper cleanup.
- **Operator `<<`:** For easy output.

**Preprocessor Alias:**  
`#define FQINFO FQInfo`

---

### `FifoItem` Class

Represents a queue node.

- **Fields:**
  - `FQINFO* m_pItem`: Pointer to `FQINFO`.
  - `FifoItem* m_pNext`: Pointer to the next item.
- **Constructors:** Inline, default parameter is `NULL`.

---

### `FQueue` Class

Implements the queue.

- **Methods:**
  - `bool FQEmpty()`: Checks if the queue is empty.
  - `int FQEnqueue(FQINFO*)`: Adds an item.
  - `FQINFO* FQDequeue()`: Removes the front item.
  - `void FQClear()`: Clears the queue.
- **Private Helper:** `void FQDel()`.
- **Memory Management:** Uses `new(nothrow)`.

---

### Exception Handling

#### Error Codes

- `FIFO_ALLOCATION_ERROR` (0x01): Memory allocation failed.
- `FIFO_QUEUE_EMPTY` (0x04): Dequeue from an empty queue.
- `OTHER_ERROR` (0x10): Other errors.

#### `FifoException` Class

- **Constructor:** Accepts error codes (default: `OTHER_ERROR`).
- **Method:** `const char* getReason()`: Returns an error description.

---

## Summary

This project demonstrates a FIFO queue with dynamic memory, robust error handling, and encapsulated components. It’s extendable and reusable for various applications.


