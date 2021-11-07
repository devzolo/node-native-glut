import path from 'path';
export const GLUT = require(path.join(__dirname, '..', 'bin', process.platform, process.arch, 'native-glut.node'));

GLUT.mainLoop = async function(): Promise<void> {
  GLUT.mainLoopBegin();
  await new Promise<void>(resolve => {
    const mainLoop = (): void => {
      if (GLUT.execState() === GLUT.EXEC_STATE_STOP) {
        resolve();
      } else {
        GLUT.mainLoopStep();
        //process.nextTick(mainLoop);
        setImmediate(mainLoop);
      }
    };
    //process.nextTick(mainLoop);
    setImmediate(mainLoop);
  });
  GLUT.mainLoopEnd();
};

export default GLUT;
