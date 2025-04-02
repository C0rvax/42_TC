# Docker Commands

## 🛠 Container Management

### List all Containers
```bash
docker ps -a
```

### Remove a Docker Container
```bash
docker rm CONTAINER_ID
```

## 🖼 Image Management

### Find IMAGE_ID
```bash
docker images
```

### Remove a Docker Image
```bash
docker rmi IMAGE_ID
```

## 📜 Logs and Execution

### View Logs
```bash
docker logs CONTAINER
```

### Exec MySQL/MariaDB in Docker
```bash
docker exec -it <CONTAINER_NAME> mysql -u <USERNAME> -p'<PASSWORD>' -h <HOST>
```

### Exec WordPress MariaDB in Docker
```bash
docker exec -it <CONTAINER_NAME> bash -c "mysql -u <USERNAME> -p'<PASSWORD>' -h <HOST> <DATABASE>"
```

## 🛠 Docker Compose Commands

### Start all services
```bash
docker-compose up -d
```

### Stop all services
```bash
docker-compose down
```

### Restart all services
```bash
docker-compose restart
```

### View running services
```bash
docker-compose ps
```

### View logs for all services
```bash
docker-compose logs -f
```

### View logs for a specific service
```bash
docker-compose logs -f <SERVICE_NAME>
```

## 📜 Service-Specific Commands

### Nginx: Test configuration
```bash
docker exec -it <NGINX_CONTAINER> nginx -t
```

### WordPress: Access WordPress CLI
```bash
docker exec -it <WORDPRESS_CONTAINER> wp --info
```

### MariaDB: Access MariaDB CLI
```bash
docker exec -it <MARIADB_CONTAINER> mysql -u <USERNAME> -p'<PASSWORD>'
```

### Adminer: Access Adminer via browser
- Open your browser and navigate to `http://<SERVER_IP>:<ADMINER_PORT>`.

### FTP Server: Test FTP connection
```bash
ftp <SERVER_IP>
```

### Redis: Access Redis CLI
```bash
docker exec -it <REDIS_CONTAINER> redis-cli
```

### Redis: Flush all cache
```bash
docker exec -it <REDIS_CONTAINER> redis-cli FLUSHALL
```

# 📌 SQL Commands

## 🗂 1. Basic Commands

### 🔍 Show available databases
```sql
SHOW DATABASES;
```

### 📌 Use a specific database
```sql
USE <DATABASE_NAME>;
```

### 📋 Show tables in a database
```sql
SHOW TABLES;
```

### 🏗 Show the structure of a table
```sql
DESCRIBE <TABLE_NAME>;
```
or
```sql
SHOW COLUMNS FROM <TABLE_NAME>;
```

## 🔨 2. Table Management

### 🛠 Create a table
```sql
CREATE TABLE <USERS> (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(100) UNIQUE,
    age INT
);
```

### ❌ Drop a table
```sql
DROP TABLE <TABLE_NAME>;
```

### ✏ Modify a table (add a column)
```sql
ALTER TABLE <USERS> ADD COLUMN address VARCHAR(255);
```

## 📝 3. Data Manipulation

### ➕ Insert data
```sql
INSERT INTO <USERS> (name, email, age) VALUES ('Alice', 'alice@example.com', 25);
```

### ✏ Update data
```sql
UPDATE <USERS> SET age = 26 WHERE name = 'Alice';
```

### 🗑 Delete data
```sql
DELETE FROM <USERS> WHERE name = 'Alice';
```

## 🔍 4. Queries and Data Selection

### 📋 Select all data from a table
```sql
SELECT * FROM <USERS>;
```

### 🎯 Filter results with WHERE
```sql
SELECT * FROM <USERS> WHERE age > 20;
```

### 📊 Sort results
```sql
SELECT * FROM <USERS> ORDER BY age DESC;
```

### 🔢 Count the number of results
```sql
SELECT COUNT(*) FROM <USERS>;
```

## 🔐 5. User and Permissions Management

### 🛡 Create a new user with permissions
```sql
CREATE USER '<USER>'@'%' IDENTIFIED BY '<PASSWORD>';
GRANT ALL PRIVILEGES ON <DATABASE_NAME>.* TO '<USER>'@'%';
FLUSH PRIVILEGES;
```
