import { createRequire } from "node:module";
import path from "node:path";

const require = createRequire(import.meta.dirname);
export const GLUT = require(
	path.join(
		import.meta.dirname,
		"..",
		"bin",
		process.platform,
		process.arch,
		"native-glut.node",
	),
);

GLUT.mainLoop = async (): Promise<void> => {
	GLUT.mainLoopBegin();
	await new Promise<void>((resolve) => {
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

GLUT.timerFunc = (
	time: number,
	cb: (value: number) => void,
	value: number,
): void => {
	setTimeout(cb, time, value);
};

export default GLUT;
