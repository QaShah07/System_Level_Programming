package com.example.library.service;

import com.example.library.model.Book;
import com.example.library.repository.BookRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookService {
    private final BookRepository repo;

    public BookService(BookRepository repo) {
        this.repo = repo;
    }

    public Book save(Book book) {
        return repo.save(book);
    }

    public List<Book> getAll() {
        return repo.findAll();
    }

    public Book getById(Long id) {
        return repo.findById(id).orElseThrow(() -> new RuntimeException("Book not found"));
    }

    public Book update(Long id, Book newBook) {
        Book book = getById(id);
        book.setTitle(newBook.getTitle());
        book.setAuthor(newBook.getAuthor());
        book.setIsbn(newBook.getIsbn());
        book.setPublicationYear(newBook.getPublicationYear());
        return repo.save(book);
    }

    public void delete(Long id) {
        repo.deleteById(id);
    }
}
