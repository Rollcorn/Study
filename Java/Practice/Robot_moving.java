
public class Robot_moving {
    public static void main(String[] args) {
        Robot robot = new Robot(34,-40, Direction.DOWN);
        moveRobot(robot, -30, -20);
    }

    public enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    }

    public static class Robot{
        //Поля класса Робот
        int x;
        int y;
        Direction dir;

        //Конструктор объекта робот
        public Robot (int x, int y, Direction dir)
        {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        //Методо получения направления робота
        public Direction getDirection() {return dir;}

        //Метод получения текущей координаты по оси Х
        public int getX() {return x;}

        //Метод получения текушей координаты по оси У
        public int getY() {return y;}

        //Метод поворота робота влево
        public void turnLeft() {
            if      (dir == Direction.UP)    {dir = Direction.LEFT;}
            else if (dir == Direction.DOWN)  {dir = Direction.RIGHT;}
            else if (dir == Direction.LEFT)  {dir = Direction.DOWN;}
            else if (dir == Direction.RIGHT) {dir = Direction.UP;}
        }

        //Метод поворта робота вправо
        public void turnRight() {
            if      (dir == Direction.UP)    {dir = Direction.RIGHT;}
            else if (dir == Direction.DOWN)  {dir = Direction.LEFT;}
            else if (dir == Direction.LEFT)  {dir = Direction.UP;}
            else if (dir == Direction.RIGHT) {dir = Direction.DOWN;}
        }

        //Метод шага робота вперед
        public void stepForward() {
            if (dir == Direction.UP)    {y++;}
            if (dir == Direction.DOWN)  {y--;}
            if (dir == Direction.LEFT)  {x--;}
            if (dir == Direction.RIGHT) {x++;}
        }
    }

    public static void moveRobot(Robot robot, int toX, int toY) {
        System.out.println("Текущее положение робота: " + robot.getX() + " : " + robot.getY()
            + " Направление: " + robot.getDirection());

        while (toX != robot.getX()){
            if((toX - robot.getX()) > 0){
                while(robot.getDirection() != Direction.RIGHT) {
                    if (robot.getDirection() == Direction.UP || robot.getDirection() == Direction.LEFT)
                        robot.turnRight();
                    else robot.turnLeft();
                }
            }else if((toX - robot.getX()) < 0){
                while(robot.getDirection() != Direction.LEFT) {
                    if ((robot.getDirection() == Direction.DOWN) || (robot.getDirection() == Direction.RIGHT))
                        robot.turnRight();
                    else robot.turnLeft();
                }
            }
            robot.stepForward();
        }

        while(toY != robot.getY()){
            if((toY - robot.getY()) > 0) {
                while(robot.getDirection() != Direction.UP) {
                    if (robot.getDirection() == Direction.LEFT || robot.getDirection() == Direction.DOWN)
                        robot.turnRight();
                    else robot.turnLeft();
                }
            }else if((toY - robot.getY()) < 0){
                while(robot.getDirection() != Direction.DOWN) {
                    if (robot.getDirection() == Direction.RIGHT || robot.getDirection() == Direction.UP)
                        robot.turnRight();
                    else robot.turnLeft();
                }
            }
            robot.stepForward();
        }

        System.out.println("Текущее положение робота: " + robot.getX() + " : " + robot.getY()
                + " Направление: " + robot.getDirection());
    }

}