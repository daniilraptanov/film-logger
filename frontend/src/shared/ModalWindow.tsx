import { FC, ReactNode, useEffect } from "react";
import { XMarkIcon } from "@heroicons/react/24/outline";


interface ModalWindowProps {
    opened: boolean;
    setOpened: (value: boolean) => void;
    title: string;
    body: ReactNode;
}

const ModalWindow: FC<ModalWindowProps> = (props) => {
    useEffect(() => {
        if (!props.opened) return;

        const handleKeyDown = (e: KeyboardEvent) => {
            if (e.key === "Escape") {
                props.setOpened(false);
            }
        };

        window.addEventListener("keydown", handleKeyDown);
        return () => window.removeEventListener("keydown", handleKeyDown);
    }, [props.opened, props.setOpened]);

    if (!props.opened) {
        return <></>;
    }

    return (
        <div className="fixed inset-0 z-50 flex items-center justify-center bg-black bg-opacity-40 backdrop-blur-sm">
            <div className="bg-neutral-900 bg-opacity-80 rounded-none shadow-2xl w-[80vw] h-[80vh] p-6 relative border border-neutral-700 flex flex-col">
            <button
                className="absolute top-2 right-2 text-gray-400 hover:text-gray-200 transition-colors text-2xl"
                onClick={() => props.setOpened(false)}
                aria-label="Закрити"
            >
                <XMarkIcon className="w-6 h-6 mt-2 mr-2 text-gray-400" />
            </button>
            <h2 className="text-xl font-semibold mb-4 text-gray-100 text-center">{props.title}</h2>
            <div className="flex-1 overflow-auto">
                {props.body}
            </div>
            </div>
        </div>
    );
};

export default ModalWindow;
