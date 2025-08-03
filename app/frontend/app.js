document.getElementById('loginForm').addEventListener('submit', async (e) => {
    e.preventDefault();
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    const response = await fetch('/login', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username, password })
    });

    const result = await response.json();
    alert(result.message);
});

document.getElementById('commentForm').addEventListener('submit', async (e) => {
    e.preventDefault();
    const comment = document.getElementById('comment').value;

    const response = await fetch('/submit-comment', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ comment })
    });

    const result = await response.json();
    alert(result.message);
});

document.getElementById('fileForm').addEventListener('submit', async (e) => {
    e.preventDefault();
    const fileInput = document.getElementById('file');
    const formData = new FormData();
    formData.append('file', fileInput.files[0]);

    const response = await fetch('/upload-file', {
        method: 'POST',
        body: formData
    });

    const result = await response.json();
    alert(result.message);
});