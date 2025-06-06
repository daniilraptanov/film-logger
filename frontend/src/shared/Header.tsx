import { NavLink } from "react-router-dom";
import FlashCameraButton from "./FlashCameraButton";

const Header = () => {
    return (
        <header className="bg-gray-900 text-white shadow-md">
            <div className="container mx-auto px-4 py-4 flex flex-col items-center">
                <FlashCameraButton />
                <h1 className="text-2xl font-semibold tracking-wide mb-3 text-center">
                    Світогляд System | Web UI
                </h1>
                <nav className="flex gap-4">
                    <NavLink
                        to="/logs"
                        className={({ isActive }) =>
                            `px-4 py-2 rounded transition-all ${
                                isActive
                                    ? "bg-green-900 hover:bg-green-600 text-white"
                                    : "bg-gray-800 text-gray-300 hover:bg-gray-700 hover:text-white"
                            }`
                        }
                    >
                        Логи
                    </NavLink>
                    <NavLink
                        to="/charts"
                        className={({ isActive }) =>
                            `px-4 py-2 rounded transition-all ${
                                isActive
                                    ? "bg-green-900 hover:bg-green-600 text-white"
                                    : "bg-gray-800 text-gray-300 hover:bg-gray-700 hover:text-white"
                            }`
                        }
                    >
                        Графіки
                    </NavLink>
                    <NavLink
                        to="/settings"
                        className={({ isActive }) =>
                            `px-4 py-2 rounded transition-all ${
                                isActive
                                    ? "bg-green-900 hover:bg-green-600 text-white"
                                    : "bg-gray-800 text-gray-300 hover:bg-gray-700 hover:text-white"
                            }`
                        }
                    >
                        Налаштування
                    </NavLink>
                </nav>
            </div>
        </header>
    );
};

export default Header;
