import java.util.LinkedList;

public class Storage {

    // 仓库容量
    private final int MAX_SIZE = 10;
    // 仓库存储的载体
    private LinkedList<Object> list = new LinkedList<>();

    public void produce() throws InterruptedException {
        while (list.size() + 1 > MAX_SIZE) {
            System.out.println("【生产者" + Thread.currentThread().getName() + "】仓库已满");
            try {// 条件不满足，生产阻塞
                list.wait();// 锁调用
            } catch (InterruptedException e) {
                //e.printStackTrace();
            }
        } // 生产条件满足，生产一个产品
        list.add(new Object());// 在链表中添加一个对象
        System.out.println("【生产者" + Thread.currentThread().getName() + "】生产一个产品，现库存" + list.size());
    }

    public void consume()throws InterruptedException {
        synchronized (list) {
            while (list.size() == 0) {
                System.out.println("【消费者" + Thread.currentThread().getName() 
						+ "】仓库为空");
                try {
                    list.wait();
                } catch (InterruptedException e) {
                    //e.printStackTrace();
                }
            }
            list.remove();
            System.out.println("【消费者" + Thread.currentThread().getName()+ "】消费一个产品，现库存" + list.size());
        //     list.notifyAll();
         }
    }
}