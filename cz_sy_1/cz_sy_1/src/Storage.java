import java.util.LinkedList;

public class Storage {

    // 仓库容量
    private final int MAX_SIZE = 10;
    // 使用双向链表仓库存储的载体
    private LinkedList<Object> list = new LinkedList<>();

    public void produce() {
        synchronized (list) {
            while (list.size() + 1 > MAX_SIZE) {
                System.out.println("【生产者" + Thread.currentThread().getName()
		                + "】   仓库已满");
                try {//条件不满足，生产阻塞
                    list.wait();//锁调用相当于W(s)
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }//生产条件满足，生产一个产品
            list.add(new Object());//在链表中添加一个对象
            System.out.println("【生产者" + Thread.currentThread().getName()
                    + "】   生产一个产品，现库存" + list.size());
            list.notifyAll();//唤醒在此对象监视器上等待的所有进程
        }
    }

    public void consume() {
        synchronized (list) {
            while (list.size() == 0) {
                System.out.println("【消费者" + Thread.currentThread().getName() 
						+ "】   仓库为空");
                try {
                    list.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            list.remove();
            System.out.println("【消费者" + Thread.currentThread().getName()
                    + "】   消费一个产品，现库存" + list.size());
            list.notifyAll();
        }
    }
}