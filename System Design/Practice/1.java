// ❌ Violation: UserService handles both user data and email notifications
public class UserService {
    public void register(User u) {
        // … save user to database …
        sendWelcomeEmail(u);
    }
    private void sendWelcomeEmail(User u) {
        // … SMTP logic …
    }
}

// ✅ Refactored: two classes, each with single duty
public class UserService {
    private UserRepository repo;
    private EmailNotifier notifier;

    public UserService(UserRepository repo, EmailNotifier notifier) {
        this.repo = repo;
        this.notifier = notifier;
    }

    public void register(User u) {
        repo.save(u);
        notifier.sendWelcome(u);
    }
}

public class EmailNotifier {
    public void sendWelcome(User u) {
        // … SMTP logic …
    }
}
